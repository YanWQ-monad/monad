// 1793.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 310;
struct EDGE {
	int to;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN];
EDGE* head[MAXN];
bool is_root[MAXN];
int n, m, value[MAXN], ans=0, f[MAXN][MAXN], g[MAXN][MAXN];

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

void dfs(const int node, const int father) {
	f[node][1] = value[node];
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		dfs(cur->to, node);
	}
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		for (int i=1; i<=m; i++)
			for (int j=1; j<=i; j++)
				g[node][i] = max(g[node][i], f[node][j] + f[cur->to][i-j]);
		for (int i=0; i<=m; i++)
			f[node][i] = g[node][i];
	}
}

int main() {
	freopen("1793.in" , "r", stdin );
	freopen("1793.out", "w", stdout);

	scanf("%d %d", &n, &m);
	m ++;
	for (int i=1, u; i<=n; i++) {
		scanf("%d %d", &u, &value[i]);
		AddEdge(u, i);
	}

	dfs(0, -1);

	printf("%d\n", f[0][m]);

	return 0;
}
