// 1627.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::abs;
using std::max;
using std::min;

const int INF  = 0x3FFFFFFF;
const int MAXQ = 4095;
const int MAXN = 60;

const int dx[] = { -1,  1,  0,  0 },
          dy[] = {  0,  0, -1,  1 };
struct QUE { int x, y, w; } q[MAXQ];
int n, m, bx, by, mat[MAXN][MAXN], dis[MAXN][MAXN], h, t, a1, a2, piz[25], cnt=0, ans=INF;
bool inQ[MAXN][MAXN], eg[MAXN][MAXN];
char buf[MAXN][MAXN];

bool isNum(const char c) {
    return c >= '0' && c <= '9';
}

void AddQue(const int x, const int y, const int w) {
	if (dis[x][y] <= w) return;
	dis[x][y] = w;
	if (inQ[x][y]) return;
	const int _pos = t & MAXQ;
	inQ[x][y] = true;
	dis[x][y] = w;
	q[_pos].x = x;
	q[_pos].y = y;
	q[_pos].w = w;
	eg[x][y] = true;
	if (q[_pos].w < q[h & MAXQ].w)
		swap(q[_pos], q[h & MAXQ]);
	t ++;
}
void GetQue(int &x, int &y, int &w) {
	const int _pos = h & MAXQ;
	x = q[_pos].x;
	y = q[_pos].y;
	w = q[_pos].w;
	inQ[x][y] = false;
	h ++;
}

void SPFA(const int bx, const int by) {
	int nowx, nowy, noww, newx, newy;
	h = t = 0;
	AddQue(bx, by, t);
	while (h != t) {
		GetQue(nowx, nowy, noww);
		noww = dis[nowx][nowy];
		for (int i=0; i<4; i++) {
			newx = nowx + dx[i];
			newy = nowy + dy[i];
			if (mat[newx][newy] == -1) continue;
			if      (mat[newx][newy] > 20 || mat[nowx][nowy] > 20) AddQue(newx, newy, noww + 2);
			else if (mat[newx][newy] == mat[nowx][nowy])           AddQue(newx, newy, noww + 1);
			else if (abs(mat[newx][newy] - mat[nowx][nowy]) == 1)  AddQue(newx, newy, noww + 3);
		}
	}
}

int main() {
	freopen("1627.in" , "r", stdin );
	freopen("1627.out", "w", stdout);
	for (int i=0; i<MAXN; i++)
		for (int j=0; j<MAXN; j++) {
			mat[i][j] = -1;
			dis[i][j] = INF;
		}

	scanf("%d %d", &n, &m);
	getchar();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			buf[i][j] = getchar();
			while (!isNum(buf[i][j]) && buf[i][j] != '$' && buf[i][j] != 'X')
				buf[i][j] = getchar();
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if      (isNum(buf[i][j])) mat[i][j] = buf[i][j] - '0' + 1;
			else if (buf[i][j] == '$') mat[i][j] = 22;
			else if (buf[i][j] == 'X') { mat[i][j] = 23; bx = i; by = j; }
		}

	SPFA(bx, by);
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (buf[i][j] == '$') {
				if (!eg[i][j]) {
					puts("-1");
					return 0;
				}
				piz[cnt ++] = dis[i][j];
			}

	for (int i=0, l1, l2; i<1<<cnt; i++) {
		l1 = l2 = a1 = a2 = 0;
		for (int j=0; j<cnt; j++)
			if (((1<<j) & i) > 0) {
				a1 += piz[j] * 2;
				l1 = max(l1, piz[j]);
			}
			else {
				a2 += piz[j] * 2;
				l2 = max(l2, piz[j]);
			}
		ans = min(ans, max(a1 - l1, a2 - l2));
	}
	
	printf("%d\n", ans);

	return 0;
}
