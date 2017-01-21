// 1625.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int INF  = 0x3FFFFFFF;
const int MAXN = 250;
const int MAXM = 600;

struct EDGE {int n, t, l;} edge[MAXM*2];
int d, p, c, f, s, head[MAXN], dis[MAXN], cnt[MAXN], ans=-INF;
bool inQ[MAXN];
int queue[MAXN], h=0, t=0;

void AddEdge(const int from, const int to, const int length) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	edge[CurEdge].l = length;
	head[from] = CurEdge;
	CurEdge ++;
}

bool SPFA(const int start) {
	dis[start] = -d;
	queue[t++ % MAXN] = start;
	while (h != t) {
		int u = queue[h++ % MAXN];
		inQ[u] = false;
		for (int i=head[u]; i!=-1; i=edge[i].t) {
			int v = edge[i].n,
			    w = edge[i].l;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inQ[v]) {
					queue[t++ % MAXN] = v;
					inQ[v] = true;
					if (++cnt[v] > c)
						return true;
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("1625.in" , "r", stdin );
	freopen("1625.out", "w", stdout);

	for (int i=0; i<MAXN; i++) {
		head[i] = -1;
		dis[i] = INF;
	}
	scanf("%d %d %d %d %d", &d, &p, &c, &f, &s);
	for (int i=0, u, v; i<p; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v, -d);
	}
	for (int i=0, u, v, w; i<f; i++) {
		scanf("%d %d %d", &u, &v, &w);
		AddEdge(u, v, w-d);
	}

	if (SPFA(s)) puts("-1");
	else {
		for (int i=1; i<=c; i++)
			ans = max(ans, -dis[i]);
		printf("%d\n", ans);
	}

	return 0;
}
