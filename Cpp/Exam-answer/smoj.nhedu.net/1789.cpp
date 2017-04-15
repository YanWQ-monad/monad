// 1789.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 100010;
struct EDGE {
	int to;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*2];
EDGE* head[MAXN];
int n, f[MAXN], g[MAXN], ans=0;

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

void dfs(const int node, const int father) {
	f[node] = 1;
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		dfs(cur->to, node);
		f[node] += f[cur->to];
		g[node] = max(g[node], f[cur->to]);
	}
	g[node] = max(g[node], n - f[node]);
}

int main() {
	freopen("1789.in" , "r", stdin );
	freopen("1789.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	dfs(1, -1);

	for (int i=1; i<=n; i++)
		if (g[i] * 2 <= n) {
			ans ++;
			printf("%d\n", i);
		}

	return 0;
}
