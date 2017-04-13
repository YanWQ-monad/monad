// 1776.cpp
#include <algorithm>
#include <cstdio>
#include <queue>
using std::queue; 
using std::max;
using std::min;

const int INF  = 0x7FFFFFFF;
const int MAXN = 52;
const int MAXG = 17;
char tmp[MAXN], mat[MAXN][MAXN];
int n, m, t, ans=0;
long long f[MAXG][1<<MAXG];
struct NODE {
	int x, y;
	NODE(const int xt=0, const int yt=0) : x(xt), y(yt) {}
	NODE operator+(const NODE other) const {
		return NODE(x + other.x, y + other.y);
	}
	bool effe() const {
		return x<n && y<m && x>=0 && y>=0;
	}
};
static const NODE ffs[] = { NODE(1,0), NODE(0,1), NODE(-1,0), NODE(0,-1) };
int curg=0;
NODE king, queen, gift[MAXG];
long long dis[MAXG+2][MAXG+2], pos[MAXN][MAXN];

queue<NODE>bfs_q;
void bfs(const NODE begin, const int gn) {
	bfs_q.push(begin);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			pos[i][j] = INF;
	pos[begin.x][begin.y] = 0;
	while (!bfs_q.empty()) {
		NODE cur = bfs_q.front(), next;
		bfs_q.pop();
		for (int i=0; i<4; i++) {
			if (!(next = cur + ffs[i]).effe() || pos[cur.x][cur.y] + 1 >= pos[next.x][next.y] || mat[next.x][next.y] == '#') continue;
			pos[next.x][next.y] = pos[cur.x][cur.y] + 1;
			bfs_q.push(next);
		}
	}
	for (int i=0; i<curg; i++)
		dis[gn][i+2] = pos[gift[i].x][gift[i].y];
	dis[gn][0] = pos[king.x ][king.y ];
	dis[gn][1] = pos[queen.x][queen.y];
}

int count(const int value) {
	int ret=0;
	for (int i=0; i<MAXG; i++)
		ret += ((1<<i)&value) > 0;
	return ret;
}

int main() {
	freopen("1776.in" , "r", stdin );
	freopen("1776.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &t);
	for (int i=0; i<n; i++) {
		scanf("%s", tmp);
		for (int j=0; j<m; j++) {
			mat[i][j] = tmp[j];
			if      (tmp[j] == 'K') king  = NODE(i, j);
			else if (tmp[j] == 'Q') queen = NODE(i, j);
			else if (tmp[j] == 'G') gift[curg++] = NODE(i, j);
		}
	}
	//printf("G : %d\n", curg);

	for (int i=0; i<MAXG; i++) {
		for (int j=0; j<MAXG; j++)
			dis[i][j] = INF;
		for (int j=0; j<(1<<MAXG); j++)
			f[i][j] = INF;
	}

	for (int i=0; i<curg; i++)
		bfs(gift[i], i+2);
	bfs(king , 0);
	bfs(queen, 1);

	for (int i=0; i<curg; i++)
		f[i][1<<i] = dis[0][i+2];
	for (int i=0; i<(1<<curg); i++) {
		if ((-i & i) == i) continue;
		for (int j=0; j<curg; j++)
			for (int k=0; k<curg; k++)
				if (((1<<j)|i)==i && ((1<<k)|i)==i && j^k)
					f[j][i] = min(f[j][i], f[k][i-(1<<j)] + (long long)dis[k+2][j+2] * count(i));
	}
	for (int i=0; i<(1<<curg); i++)
		for (int j=0; j<curg; j++)
			if ((i|(1<<j))==i && f[j][i] + dis[j+2][1] * (count(i) + 1) <= t)
				ans = max(ans, count(i));

	printf("%d\n", ans);

	return 0;
}
