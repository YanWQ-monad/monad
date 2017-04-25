// 1412.cpp
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

const int INF  = 0xFFFFFFF;
const int MAXN = 100010;
const int MAXM = 500010;

struct EDGE {
	int to;
	EDGE *prep, *next;
};

template <int MAXV, int MAXL>
class EDGES {
private:
	int curE;
	EDGE edge[MAXL], *head[MAXV], *tail[MAXV];
public:
	EDGES() : curE(0) {}
	void AddEdge(const int u, const int v) {
		static int curE = 0;
		edge[curE].to   = v;
		edge[curE].next = NULL;
		edge[curE].prep = tail[u];
		if (tail[u]) tail[u]->next = edge+curE;
		tail[u] = edge+curE;
		head[u] = head[u]? head[u]:edge+curE;
		curE ++;
	}
	const EDGE* enumNode(const int node) const {
		return head[node];
	}
};
struct PAIR { int l, r; } h[MAXN];
EDGES<MAXN, MAXM> edge, topo, pshr;
int n, m, value[MAXN], stap[MAXN], dfn[MAXN], low[MAXN], cnt=0, belong[MAXN], stop=0, Bcnt=0;
int topo_stack[MAXN], stack_pos, f[MAXN], g[MAXN];
bool instack[MAXN], visit[MAXN];

void tarjan(const int cur) {
	dfn[cur] = low[cur] = ++ cnt;
	instack[cur] = true;
	stap[stop++] = cur;

	for (const EDGE *ce=edge.enumNode(cur); ce; ce=ce->next) {
		if (!dfn[ce->to]) {
			tarjan(ce->to);
			low[cur] = min(low[cur], low[ce->to]);
		}
		else if(instack[ce->to])
			low[cur] = min(low[cur], dfn[ce->to]);
	}

	if (dfn[cur] == low[cur]) {
		int v;
		do {
			v = stap[--stop];
			instack[v] = false;
			belong[v] = Bcnt;
		} while(v != cur);
		Bcnt ++;
	}
}

void topo_sort(int cur) {
	if (instack[cur]) return;
	instack[cur] = true;
	for (const EDGE *ce=topo.enumNode(cur); ce; ce=ce->next)
		topo_sort(ce->to);
	topo_stack[stack_pos++] = cur;
}

int main() {
	freopen("1412.in" , "r", stdin );
	freopen("1412.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &value[i]);
	for (int i=0, u, v, mode; i<m; i++) {
		scanf("%d %d %d", &u, &v, &mode);
		edge.AddEdge(u, v);
		if (mode == 2)
			edge.AddEdge(v, u);
	}

	for (int i=1; i<=n; i++)
		if (!dfn[i])
			tarjan(i);

	for (int i=0; i<Bcnt; i++)
		f[i] = h[i].l = INF;
	for (int i=1; i<=n; i++) {
		for (const EDGE *ce=edge.enumNode(i); ce; ce=ce->next)
			if (belong[i] != belong[ce->to]) {
				topo.AddEdge(belong[i], belong[ce->to]);
				pshr.AddEdge(belong[ce->to], belong[i]);
			}
		h[belong[i]].l = min(h[belong[i]].l, value[i]);
		h[belong[i]].r = max(h[belong[i]].r, value[i]);
	}

	topo_sort(belong[1]);
	for (int i=stack_pos-1; i>=0; i--) {
		int cur = topo_stack[i];
		f[cur] = h[cur].l;
		for (const EDGE *ce=pshr.enumNode(i); ce; ce=ce->next) {
			g[cur] = max(g[cur], g[ce->to]);
			f[cur] = min(f[cur], f[ce->to]);
		}
		g[cur] = max(g[cur], h[cur].r - f[cur]);
	}

	printf("%d\n", g[belong[n]]);

	return 0;
}
