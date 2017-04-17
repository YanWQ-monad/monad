// 1795.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 55;
const int MAXS = 105;

struct EDGE {
	int to;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*2];
EDGE* head[MAXN];
int n, s, value[MAXN], f[MAXN][MAXS], g[MAXN][MAXS], f2[MAXN][MAXS], g2[MAXN][MAXS];

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

void dfs(const int node, const int father) {
	for (int i=0; i<=s; i++)
		g[node][i] = f[node][i] = value[node];
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		dfs(cur->to, node);
		for (int i=1; i<=s; i++) {
			f2[node][i] = f[node][i];
			for (int j=0; i-j-1 >= 0; j++) {
				f2[node][i] = max(f2[node][i], g[node][j] + f[cur->to][i-j-1]);
				if (i-j-2>=0) f2[node][i] = max(f2[node][i], f[node][j] + g[cur->to][i-j-2]);
			}
		}
		for (int i=1; i<=s; i++) {
			g2[node][i] = g[node][i];
			for (int j=0; j<=s && i-j-2>=0; j++) {
				g2[node][i] = max(g2[node][i], g[node][j] + g[cur->to][i-j-2]);
		}
		for (int i=1; i<=s; i++) {
			f[node][i] = f2[node][i];
			g[node][i] = g2[node][i];
			f2[node][i] = g2[node][i] = 0;
		}
	}
}

int main() {
	freopen("1795.in" , "r", stdin );
	freopen("1795.out", "w", stdout);

	scanf("%d %d", &n, &s);
	for (int i=1; i<=n; i++)
		scanf("%d", &value[i]);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	dfs(1, -1);

	printf("%d\n", f[1][s]);

	return 0;
}
