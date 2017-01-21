// 1626.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;

const int INF  = 0x3FFFFFFF;
const int MAXN = 260;

struct EDGE {int value, point;} len[MAXN][MAXN];
int n, m, p, node[MAXN], th[MAXN];
bool eg[MAXN][MAXN];

int TH_sort(const int a, const int b) {
	return node[a] < node[b];
}

int main() {
	freopen("1626.in" , "r", stdin );
	freopen("1626.out", "w", stdout);
	for (int i=0; i<MAXN; i++) {
		th[i] = i;
		for (int j=0; j<MAXN; j++)
			len[i][j].value = len[i][j].point = INF;
	}

	scanf("%d %d %d", &n, &m, &p);
	for (int i=1; i<=n; i++) {
		scanf("%d", &node[i]);
	}
	for (int i=0, u, v, w; i<m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if (!eg[u][v] || w < len[u][v].value) {
			len[u][v].value = w;
			len[u][v].point = max(node[u], node[v]);
			eg[v][u] = eg[u][v] = true;
			len[v][u] = len[u][v];
		}
	}
	sort(th+1, th+n+1, TH_sort);
	for (int kt=1; kt<=n; kt++)
		for (int it=1; it<=n; it++)
			for (int jt=1; jt<=n; jt++) {
				int i = th[it],
				    j = th[jt],
				    k = th[kt];
				if (eg[i][k] && eg[k][j] && (!eg[i][j] || len[i][k].value + len[k][j].value + max(len[i][k].point, len[k][j].point) < len[i][j].value + len[i][j].point)) {
					len[i][j].value = len[i][k].value + len[k][j].value;
					len[i][j].point = max(len[i][k].point, len[k][j].point);
					len[j][i] = len[i][j];
					eg[j][i] = eg[i][j] = true;
				}

			}

	for (int i=0,x , y; i<p; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", len[x][y].value + len[x][y].point);
	}



	return 0;
}
