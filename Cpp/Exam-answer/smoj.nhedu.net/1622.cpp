// 1622.cpp
#include <algorithm>
#include <cstdio>
using std::swap;

const int INF  = 0x3FFFFFFF;
const int MAXN = 510;
const int MAXM = 6000;

struct EDGE {int f, t, d;} edge[MAXM];
int f, n, m, w, dis[MAXN], ans=INF, head[MAXN];
bool used[MAXN];

int Bellman_Ford(const int start) {
	dis[start] = 0;
	for (int i=1, edit; i<=n; i++) {
		edit = false;
		for (int j=0; j<=m*2+w; j++) {
			if (edge[j].d != INF && dis[edge[j].f] + edge[j].d < dis[edge[j].t]) {
				edit = true;
				dis[edge[j].t] = dis[edge[j].f] + edge[j].d;
			}
		}
		if (!edit) break;
		if (edit && i==n) return true;
	}
	return false;
}

int main() {
	freopen("1622.in" , "r", stdin );
	freopen("1622.out", "w", stdout);

	scanf("%d", &f);
	while (f --) {
		for (int i=0; i<MAXN; i++) {
			dis[i] = INF;
		}
		scanf("%d %d %d", &n, &m, &w);
		for (int i=0; i<m; i++) {
			scanf("%d %d %d", &edge[i*2].f, &edge[i*2].t, &edge[i*2].d);
			edge[i*2+1] = edge[i*2];
			swap(edge[i*2+1].f, edge[i*2+1].t);
		}
		for (int i=0; i<w; i++) {
			scanf("%d %d %d", &edge[m*2+i].f, &edge[m*2+i].t, &edge[m*2+i].d);
			edge[m*2+i].d = -edge[m*2+i].d;
		}
		printf("%s\n", Bellman_Ford(1)? "YES":"NO");

	}
	return 0;
}
