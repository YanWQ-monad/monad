// 1828.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::min;

const int INF  = 0xFFFFFFF;
const int MAXN = 310;
struct EDGE {
	int to, w;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*2];
EDGE* head[MAXN];
int n, y, z, f[MAXN][MAXN][2], g[MAXN][MAXN][2], sort_a[MAXN], pos;

void AddEdge(const int u, const int v, const int w) {
	static int curE = 0;
	edge[curE].to   = v;
	edge[curE].w    = w;
	edge[curE].next = head[u];
	head[u]         = edge+curE;
	curE ++;
}

void dfs(const int cur, const int father) {
	f[cur][0][0] = f[cur][1][1] = 0;
	for (EDGE *ce=head[cur]; ce; ce=ce->next) {
		if (ce->to == father) continue;
		dfs(ce->to, cur);
		for (int i=0; i<=z; i++)
			for (int j=0; j<=i; j++) {
				if (i>=j) g[cur][i][0] = min(g[cur][i][0], f[cur][j][0] + min(f[ce->to][i-j][0]+(y==2? ce->w:0), f[ce->to][i-j][1]));
				if (j)    g[cur][i][1] = min(g[cur][i][1], f[cur][j][1] + min(f[ce->to][i-j][1]+(      ce->w  ), f[ce->to][i-j][0]));
			}
		for (int i=0; i<=z; i++) {
			f[cur][i][0] = g[cur][i][0];
			f[cur][i][1] = g[cur][i][1];
			g[cur][i][0] = g[cur][i][1] = INF;
		}
	}
}

int main() {
	freopen("1828.in" , "r", stdin );
	freopen("1828.out", "w", stdout);

	scanf("%d %d %d", &n, &y, &z);
	for (int i=0, u, v, w; i<n-1; i++) {
		scanf("%d %d %d", &u, &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			g[i][j][0] = g[i][j][1] = f[i][j][0] = f[i][j][1] = INF;

	dfs(1, -1);

	if (y+z-1 > n) puts("-1");
	else           printf("%d\n", f[1][z][1]);

	return 0;
}
