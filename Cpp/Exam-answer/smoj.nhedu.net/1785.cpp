// 1785.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int INF  = 0x3FFFF;
const int MAXN = 210;
struct EDGE {
	int to;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*2];
EDGE* head[MAXN];
int n, p, e[MAXN], f[MAXN][MAXN][MAXN], sons[MAXN], ans=INF;

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

void dfs(const int node, const int father) {
	f[node][0][0] = 0;
	f[node][0][1] = e[node];
	int curn = 1;
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next, curn++) {
		if (cur->to == father) continue;
		f[node][curn][0] = 0;
		f[node][curn][1] = e[node];
	//	if (cur->to == p) continue;
		dfs(cur->to, node);
		for (int i=2; i<=p; i++) {
			f[node][curn][i] = f[node][curn-1][i];
			for (int j=1; j<i; j++)
				f[node][curn][i] = min(f[node][curn][i], f[node][curn-1][i-j] + f[cur->to][sons[cur->to]][j] - 2);
		}
	}
}

int main() {
	freopen("1785.in" , "r", stdin );
	freopen("1785.out", "w", stdout);

	scanf("%d %d", &n, &p);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		if (u > v)
			u ^= v ^= u ^= v;
		AddEdge(u, v);
	//	AddEdge(v, u);
		sons[u] ++;
		e[u] ++;
		e[v] ++;
	}

	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int k=0; k<=n; k++)
				f[i][j][k] = INF;

	dfs(1, -1);

	for (int i=1; i<=n; i++)
		ans = min(ans, f[i][sons[i]][p]);
	printf("%d\n", ans);

	return 0;
}
