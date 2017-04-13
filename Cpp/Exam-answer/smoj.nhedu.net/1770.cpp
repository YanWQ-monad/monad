// 1770.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int MAXN = 1010;
const int MAXL = 210;
int n, l, c[MAXL][MAXL], r[MAXN], f[MAXL][MAXL], g[MAXL][MAXL];

void clear_next() {
	for (int i=1; i<=l; i++)
		for (int j=1; j<=l; j++) {
			f[i][j] = g[i][j];
			g[i][j] = 0x6FFFFFFF;
		}
}

void dp_next(const int cur) {
	for (int i=1; i<=l; i++)
		for (int j=1; j<=l; j++)
			if (f[i][j] < 0x6FFFFFFF && i != r[cur-1] && j != r[cur-1]) {
				g[i][   j    ] = min(g[i][   j    ], f[i][j] + c[r[cur-1]][r[cur]]);
				g[i][r[cur-1]] = min(g[i][r[cur-1]], f[i][j] + c[   j    ][r[cur]]);
				g[j][r[cur-1]] = min(g[j][r[cur-1]], f[i][j] + c[   i    ][r[cur]]);
			}
}

int collect() {
	int ret = 0x6FFFFFFF;
	for (int i=1; i<=l; i++)
		for (int j=1; j<=l; j++)
			ret = min(ret, g[i][j]);
	return ret;
}

void print() {
	for (int i=1; i<=l; i++)
		for (int j=1; j<=l; j++)
			if (g[i][j] < 0x6FFFFFFF) {
				printf("%d %d : %d\n", i, j, g[i][j]);
			}
}

int main() {
	freopen("1770.in" , "r", stdin );
	freopen("1770.out", "w", stdout);

	scanf("%d %d", &l, &n);
	for (int i=1; i<=l; i++)
		for (int j=1; j<=l; j++)
			scanf("%d", &c[i][j]);
	for (int i=1; i<=n; i++)
		scanf("%d", &r[i]);
	for (int i=1; i<=l; i++)
		for (int j=1; j<=l; j++)
			g[i][j] = 0x6FFFFFFF;
	g[1][2] = 0;
	r[0] = 3;

	for (int i=1; i<=n; i++) {
		clear_next();
		dp_next(i);
	}
	
	printf("%d\n", collect());

	return 0;
}
