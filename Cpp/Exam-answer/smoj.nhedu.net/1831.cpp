// 1831.cpp
#include <algorithm>
#include <cstdio>
using std::min;
using std::max;

struct EDGE {
	int to;
	EDGE *next;
};

template <int MAXV, int MAXL>
class mEdges {
private:
	int curE;
	EDGE edge[MAXL], *head[MAXV];
public:
	mEdges() : curE(0) {}
	void AddEdge(const int u, const int v) {
		edge[curE].to   = v;
		edge[curE].next = head[u];
		head[u] = edge+curE;
		curE ++;
	}
	const EDGE* enumNode(const int node) const {
		return head[node];
	}
	void clear() {
		curE = 0;
		for (int i=0; i<MAXV; i++)
			head[i] = NULL;
	}
};

const int MAXN = 50010;
const int MAXM = 60010;
mEdges<MAXN, MAXM> edge, topo, befo;
int r, n, m, value[MAXN], stap[MAXN], dfn[MAXN], low[MAXN], cnt=0, belong[MAXN], stop=0, Bcnt=0, topo_stack[MAXN], stack_pos, f[MAXN], g[MAXN], ans;
bool instack[MAXN], visit[MAXN];

void init() {
	edge.clear();
	topo.clear();
	befo.clear();
	ans = 0;
	cnt = stop = Bcnt = stack_pos = 0;
	for (int i=0; i<MAXN; i++) {
		g[i] = f[i] = topo_stack[i] = belong[i] = stap[i] = dfn[i] = low[i] = 0;
		visit[i] = instack[i] = false;
	}
}

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
		Bcnt ++;
		int v;
		do {
			v = stap[--stop];
			instack[v] = false;
			belong[v] = Bcnt;
		} while(v != cur);
	}
}

void topo_sort(int cur) {
	if (visit[cur]) return;
	visit[cur] = true;
	for (const EDGE *ce=topo.enumNode(cur); ce; ce=ce->next)
		topo_sort(ce->to);
	topo_stack[stack_pos++] = cur;
}

int main() {
	freopen("1831.in" , "r", stdin );
	freopen("1831.out", "w", stdout);

	scanf("%d", &r);
	while (r--) {
		init();
		scanf("%d %d", &n, &m);
		for (int i=1; i<=n; i++)
			scanf("%d", &value[i]);
		for (int i=0, u, v; i<m; i++) {
			scanf("%d %d", &u, &v);
			edge.AddEdge(u+1, v+1);
		}

		for (int i=n; i; i--)
			if (!dfn[i])
				tarjan(i);

		for (int i=1; i<=n; i++) {
			for (const EDGE *ce=edge.enumNode(i); ce; ce=ce->next)
				if (belong[i] != belong[ce->to]) {
					topo.AddEdge(belong[i], belong[ce->to]);
					befo.AddEdge(belong[ce->to], belong[i]);
				}
			g[belong[i]] = f[belong[i]] = max(f[belong[i]], f[belong[i]] + value[i]);
		}

		for (int i=1; i<=Bcnt; i++)
			if (!visit[i])
				topo_sort(i);

		for (int i=stack_pos, v; i>=0; i--)
			for (const EDGE *ce=befo.enumNode(v=topo_stack[i]); ce; ce=ce->next) {
				g[v] = max(g[v], f[v] + g[ce->to]);
				ans = max(g[v], ans);
			}
		printf("%d\n", ans);
	}


	return 0;
}
