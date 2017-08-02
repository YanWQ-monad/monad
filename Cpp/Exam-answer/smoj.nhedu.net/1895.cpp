// 1895.cpp
#include <cstring>
#include <cstdio>

const int MAXN = 100010;
struct EDGE {
	int v;
	EDGE *next;
	EDGE() : v(0), next(NULL) {}
}edge[MAXN], *head[MAXN];
int n, s, t, len[MAXN], child[MAXN], deep[MAXN], father[MAXN], ans1, ans2;
char st[1000];

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].v    = v;
	edge[curE].next = head[u];
	head[u]         = edge + curE;
	curE ++;
}

void dfs(const int cur) {
	for (EDGE *curE=head[cur]; curE!=NULL; curE=curE->next) {
		deep[curE->v] = deep[cur] + 1;
		dfs(curE->v);
	}
}

int findA(int s, int t) {
	while (s != t) {
		if (deep[s] < deep[t]) t = father[t];
		else                   s = father[s];
	}
	return s;
}

int main() {
	freopen("1895.in" , "r", stdin );
	freopen("1895.out", "w", stdout);

	scanf("%d %d %d", &n, &s, &t);
	for (int i=0, u, v; i<n; i++) {
		scanf("%d %d %s", &v, &u, st);
		father[v] = u;
		len[v] = strlen(st);
		child[u] ++;
		AddEdge(u, v);
	}

	dfs(0);

	int a = findA(s, t);

	for (int i=s; ; i=father[i]) {
		ans1 += len[i];
		ans2 += child[i];
		if (i == a) break;
	}
	for (int i=t; i!=a; i=father[i]) {
		ans1 += len[i];
		ans2 += child[i];
	}
	ans2 -= child[s] + child[t];
	printf("%d\n%d\n", ans1, ans2);

	return 0;
}
