// 1630.cpp
#include <cstdio>

const int INF  = 0x3FFFFFFF;
const int MAXN = 1000;
const int MAXM = 1000;

int bit[MAXN][6];

int Get(const int node, const int pos) {
	return bit[node][pos/20] & (1 << (pos % 20));
}

void Set(const int node, const int pos) {
	bit[node][pos/20] |= (1 << (pos % 20));
}

void Copy(const int from, const int to) {
	for (int i=0; i<6; i++)
		bit[from][i] |= bit[to][i];
}

struct EDGE {int f, t, d;} edge[MAXM];
int f, n, m, dis[MAXN], ans=INF, head[MAXN];
bool used[MAXN], to[MAXN], effe[MAXN], fh[MAXN];

int Bellman_Ford(const int start) {
	dis[start] = 0;
	effe[start] = true;
	Set(start, start);
	for (int i=1, edit; i<=2*n; i++) {
		edit = false;
		for (int j=0; j<m; j++) {
			if (effe[edge[j].f] && edge[j].d != INF && dis[edge[j].f] + edge[j].d < dis[edge[j].t]) {
				if (Get(edge[j].t, edge[j].t)) {
					fh[edge[j].t] = true;
				}
				edit = true;
				dis[edge[j].t] = dis[edge[j].f] + edge[j].d;
				to[edge[j].t] = true;
				effe[edge[j].t] = true;
				Copy(edge[j].f, edge[j].t);
				Set(edge[j].t, edge[j].f);
				fh[edge[j].t] = fh[edge[j].t] || fh[edge[j].f];
			}
		}
		if (!edit) return false;
	}
	return true;
}

int main() {
	freopen("1630.in" , "r", stdin );
	freopen("1630.out", "w", stdout);
	for (int i=0; i<MAXN; i++)
		dis[i] = INF;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++)
		scanf("%d %d %d", &edge[i].f, &edge[i].t, &edge[i].d);

	Bellman_Ford(1);

	if      (fh[n])                   puts("-1000000000");
	else if (!to[n] || dis[n] == INF) puts( "1000000000");
	else                              printf("%d\n", dis[n]);

	return 0;
}
