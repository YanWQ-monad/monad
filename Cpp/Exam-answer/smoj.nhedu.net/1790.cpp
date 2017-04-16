// 1790.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 100010;
const int MAXX = 21;
struct EDGE {
	int to;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*2];
EDGE* head[MAXN];
int n, x, value[MAXN], f[MAXN][MAXX], father[MAXN], ans=0;

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

void dfs(const int node, const int father) {
	f[node][0] = value[node];
	::father[node] = father;
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		dfs(cur->to, node);
		for (int i=1; i<=x; i++)
			f[node][i] += f[cur->to][i-1];
	}
}

int GetAns(const int node) {
	int ret = 0;
	for (int i=0; i<=x; i++)
		ret += f[node][i];
	for (int i=x-1, cur=node; i>=0 && father[cur] != -1; i--, cur=father[cur]) {
		for (int j=1; j<=i; j++)
			ret += f[father[cur]][j] - f[cur][j-1];
		ret += value[father[cur]];
	}
	return ret;
}

int main() {
	freopen("1790.in" , "r", stdin );
	freopen("1790.out", "w", stdout);

	scanf("%d %d", &n, &x);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}
	for (int i=1; i<=n; i++)
		scanf("%d", &value[i]);

	dfs(1, -1);

	for (int i=1; i<=n; i++)
		printf("%d\n", GetAns(i));

	return 0;
}
