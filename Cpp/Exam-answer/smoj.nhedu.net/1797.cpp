// 1797.cpp
#include <algorithm>
#include <cstdio>
#include <queue>
using std::queue;
using std::min;

const int INF  = 0x5FFFFFFF;
const int MAXN = 42;
const int MAXF = 12;

struct EDGE {
	int to, comp;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*MAXF];
struct QUER { int node, set; };
EDGE* head[MAXN];
int r, n, g, cost[MAXN][MAXF], f[MAXN][1<<MAXF], u[MAXF][MAXN][MAXN], curE;

void AddEdge(const int u, const int v, const int company) {
	edge[curE].to = v;
	edge[curE].next = head[u];
	edge[curE].comp = company;
	head[u] = &(edge[curE]);
	curE ++;
}

int count(const int value) {
	int ret = 0;
	for (int i=0; i<g; i++)
		ret += !!(value&(1<<i));
	return ret;
}

void init() {
	curE = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<(1<<g); j++)
			f[i][j] = INF;
	for (int i=0; i<g; i++)
		for (int u=0; u<n; u++)
			for (int v=0; v<n; v++)
				::u[i][u][v] = false;
	for (int i=0; i<n; i++)
		head[i] = NULL;
	for (int i=0; i<2*n; i++)
		edge[i] = EDGE();
}

queue<QUER> q;
void SPFA() {
	f[0][0] = 0;
	q.push((QUER){0,0});
	while (!q.empty()) {
		QUER now = q.front();
		q.pop();
		for (int i=0; i<g; i++)
			if (!(now.set & (1 << i))) {
				int new_set = now.set + (1 << i);
				if (count(new_set) <= 3 && f[now.node][now.set] + cost[now.node][i] < f[now.node][new_set]) {
					f[now.node][new_set] = f[now.node][now.set] + cost[now.node][i];
					q.push((QUER){now.node, new_set});
				}
			}
		for (EDGE *cur=head[now.node]; cur!=NULL; cur=cur->next)
			if (u[cur->comp][now.node][cur->to] && now.set&(1<<cur->comp) && f[now.node][now.set] < f[cur->to][now.set-(1<<cur->comp)]) {
				f[cur->to][now.set-(1<<cur->comp)] = f[now.node][now.set];
				q.push((QUER){cur->to, now.set-(1<<cur->comp)});
			}
	}
}

int main() {
	freopen("1797.in" , "r", stdin );
	freopen("1797.out", "w", stdout);

	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &n, &g);
		init();
		for (int i=0, m; i<g; i++) {
			scanf("%d", &m);
			for (int j=0, u, v; j<m; j++) {
				scanf("%d %d", &u, &v);
				AddEdge(u, v, i);
				::u[i][u][v] = true;
			}
		}
		for (int i=0; i<n; i++)
			for (int j=0; j<g; j++)
				scanf("%d", &cost[i][j]);

		SPFA();

		for (int i=1; i<n; i++)
			printf("%d ", f[i][0]>=INF? -1:f[i][0]);
		puts("");
	}

	return 0;
}
