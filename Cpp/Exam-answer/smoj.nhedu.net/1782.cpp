// 1782.cpp
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
int n, value[MAXN], f[MAXN][2];
bool u[MAXN];

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = edge+curE;
	curE ++;
}

bool dfs(const int node) {
	if (u[node]) return false;
	int no=0, yes=value[node];
	u[node] = true;
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (!dfs(cur->to)) continue;
		no  += max(f[cur->to][0], f[cur->to][1]);
		yes += f[cur->to][0];
	}
	f[node][0] = no;
	f[node][1] = yes;
	return true;
}

int main() {
	freopen("1782.in" , "r", stdin );
	freopen("1782.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &value[i]);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	dfs(1);

	printf("%d\n", max(f[1][1], f[1][0]));

	return 0;
}
