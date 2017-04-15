// 1784.cpp
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
int n, f[MAXN][2];
bool u[MAXN];

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

bool dfs(const int node) {
	if (u[node]) return false;
	f[node][1] = 1;
	u[node] = true;
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (!dfs(cur->to)) continue;
		f[node][0] += max(f[cur->to][0], f[cur->to][1]);
		f[node][1] += f[cur->to][0];
	}
	return true;
}

int main() {
	freopen("1784.in" , "r", stdin );
	freopen("1784.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	dfs(1);

	printf("%d\n", max(f[1][1], f[1][0]));

	return 0;
}
