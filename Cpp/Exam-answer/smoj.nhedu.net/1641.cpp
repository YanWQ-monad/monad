// 1641.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int INF  = 0x3FFFFFFF;
const int MAXN = 1010;
struct NODE { int x, y; } exp[MAXN], pub[MAXN];
int n, m, f[MAXN][MAXN], g[MAXN][MAXN];

int dis(const NODE lhs, const NODE rhs) {
	return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}

int main() {
	freopen("1641.in" , "r", stdin );
	freopen("1641.out", "w", stdout);

	for (int i=0; i<MAXN; i++)
		for (int j=0; j<MAXN; j++)
			f[i][j] = g[i][j] = INF;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d %d", &exp[i].x, &exp[i].y);
	for (int i=1; i<=m; i++)
		scanf("%d %d", &pub[i].x, &pub[i].y);

	f[1][0] = 0;
	g[1][1] = dis(exp[1], pub[1]);
	for (int i=2; i<=m; i++)
		g[1][i] = g[1][i-1] + dis(pub[i], pub[i-1]);
	for (int i=2; i<=n; i++)
		for (int j=0; j<=m; j++) {
			/* = */f[i][j] = min(f[i-1][ j ] + dis(exp[i], exp[i-1]), g[i-1][ j ] + dis(exp[i], pub[j]));
			if (j) g[i][j] = min(g[ i ][i-1] + dis(pub[i], pub[i-1]), f[ i ][j-1] + dis(exp[i], pub[j]));
		}

	printf("%d\n", f[n][m]);

	return 0;
}
