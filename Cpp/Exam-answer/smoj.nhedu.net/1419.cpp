// 1419.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int MAXN = 10010;
const int MAXM = 50010;

struct EDGE {
	int to;
	EDGE *next;
};

template <int MAXV, int MAXL>
class EDGES {
private:
	int curE;
	EDGE edge[MAXL], *head[MAXV];
public:
	EDGES() : curE(0) {}
	void AddEdge(const int u, const int v) {
		static int curE = 0;
		edge[curE].to   = v;
		edge[curE].next = head[u];
		head[u] = edge+curE;
		curE ++;
	}
	const EDGE* enumNode(const int node) const {
		return head[node];
	}
};
EDGES<MAXN, MAXM> strn, topo;
int n, m, stack=0, topo_stack[MAXN], pos, ans=0;
int stap[MAXN], dfn[MAXN], low[MAXN], cnt=0, belong[MAXN], stop=0, Bcnt=0;
bool instack[MAXN], u[MAXN];

void tarjan(const int cur) {
	dfn[cur] = low[cur] = ++cnt;
	instack[cur] = true;
	stap[++stop] = cur;
	for (const EDGE *ce=strn.enumNode(cur); ce; ce=ce->next) {
		int v = ce -> to;
		if (!dfn[v]) {
			tarjan(v);
			low[cur] = min(low[cur], low[v]);
		}
		else if (instack[v])
			low[cur] = min(low[cur], dfn[v]);
	}
	if (dfn[cur] == low[cur]) {
		Bcnt ++;
		int v;
		do {
			v = stap[stop--];
			instack[v] = false;
			belong[v] = Bcnt;
		}while(v != cur);
	}
}

void topo_sort(const int cur) {
	u[cur] = true;
	for (const EDGE *ce=topo.enumNode(cur); ce; ce=ce->next) {
		if (u[ce->to]) continue;
		topo_sort(ce->to);
	}
	topo_stack[stack--] = cur;
}

int main() {
	freopen("1419.in" , "r", stdin );
	freopen("1419.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (size_t i=0, u, v; i<m; i++) {
		scanf("%d %d", &u, &v);
		strn.AddEdge(u, v);
	}
	for (int i=1; i<=n; i++)
		if (!dfn[i])
			tarjan(i);

	for (int i=1; i<=n; i++)
		for (const EDGE *ce=strn.enumNode(i); ce; ce=ce->next)
			if (belong[ce->to] != belong[i])
				topo.AddEdge(belong[i], belong[ce->to]);

	stack = Bcnt;
	for (int i=1; i<=Bcnt; i++)
		if (!u[i])
			topo_sort(i);

	for (int i=1; i<Bcnt; i++)
		if (topo.enumNode(topo_stack[i]) == NULL) {
			puts("0");
			return 0;
		}

	for (int j=1; j<=n; j++)
		if (belong[j] == topo_stack[Bcnt])
			ans ++;
	printf("%d\n", ans);


	return 0;
}
