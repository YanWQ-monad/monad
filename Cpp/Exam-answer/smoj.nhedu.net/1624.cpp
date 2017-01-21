// 1624.cpp
#include <algorithm>
#include <cstdio>
using std::swap;

const int INF  = 0x3FFFFFFF;
const int MAXQ = 0xFFF;
const int MAXN = 60;
const int MAXM = 60;
int z, n, m, k, h, t;
int p[MAXN], enter[MAXM], quit[MAXM], dis[MAXN][MAXM], move[MAXN][MAXM];
struct QUET {int i, j;} queue[MAXQ];
bool v[MAXN][MAXM];

void init() {
	for (int i=0; i<MAXN; i++)
		for (int j=0; j<MAXM; j++) {
			move[i][j] = dis[i][j] = INF;
			v[i][j] = false;
		}
}

void read() {
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &p[i]);
	scanf("%d", &m);
	for (int i=0; i<m; i++)
		scanf("%d", &enter[i]);
	scanf("%d", &m);
	for (int i=0; i<m; i++)
		scanf("%d", &quit[i]);
	scanf("%d", &k);	
}

void push(const int i, const int j) {
	if (v[i][j]) return;
	const int pos = (t++) & MAXQ, hpos = h & MAXQ;
	queue[pos].i = i;
	queue[pos].j = j;
	v[i][j] = true;
	if (dis[i][j] < dis[queue[hpos].i][queue[hpos].j])
		swap(queue[pos], queue[hpos]);
}

void gett(int &i, int &j) {
	const int pos = (h++) & MAXQ;
	i = queue[pos].i;
	j = queue[pos].j;
	v[i][j] = false;
}

void relax(const int fi, const int fj, const int ti, const int tj, const int w) {
	if (dis[fi][fj] + w == dis[ti][tj] && move[fi][fj] + 1 < move[ti][tj]) {
		move[ti][tj] = move[fi][fj] + 1;
		push(ti, tj);
	}
	if (dis[fi][fj] + w < dis[ti][tj]) {
		dis [ti][tj] = dis[fi][fj] + w;
		move[ti][tj] = move[fi][fj] + 1;
		push(ti, tj);
	}
}

void SPFA(const int start) {
	int i, j;
	move[start][0] = dis[start][0] = h = t = 0;
	push(start, 0);
	while (h != t) {
		gett(i, j);
		if (i > 0 && p[i-1] != -1) relax(i, j, i-1, j, p[i-1]);
		if (i+1<n && p[i+1] != -1) relax(i, j, i+1, j, p[i+1]);
		for (int l=0; l<m; l++)
			if (enter[l] == i && p[quit[l]] != -1 && j+1 <= m)
				relax(i, j, quit[l], j+1, k+j);
	}
}

void print() {
	int ans=INF, moves=0;
	for (int i=0; i<=m; i++)
		if (dis[n-1][i] < ans || (dis[n-1][i] == ans && move[n-1][i] < moves)) {
			ans   = dis [n-1][i];
			moves = move[n-1][i];
		}
	if (ans == INF) puts("-1 -1");
	else            printf("%d %d\n", ans, moves);
}

int main() {
	freopen("1624.in" , "r", stdin );
	freopen("1624.out", "w", stdout);

	scanf("%d", &z);
	while (z--) {
		init();
		read();
		SPFA(0);
		print();
	}

	return 0;
}
