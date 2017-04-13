// 1775.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 13;
int r, n, m, v[MAXN], e[MAXN][MAXN];
long long f[1<<MAXN][MAXN][MAXN], g[1<<MAXN][MAXN][MAXN], ans=0, tot=0;

typedef int INT;
#define int long long

void init() {
	ans = tot = 0;
	for (int i=0; i<MAXN; i++) {
		v[i] = 0;
		for (int j=0; j<MAXN; j++) {
			e[i][j] = false;
			for (int k=0; k<(1<<MAXN); k++) {
				f[k][i][j] = -1;
				g[k][i][j] = 0;
			}
		}
	}
}

int count(const int value) {
	int ret=0;
	for (int i=0; i<MAXN; i++)
		ret += ((1<<i)&value) > 0;
	return ret;
}

INT main() {
	freopen("1775.in" , "r", stdin );
	freopen("1775.out", "w", stdout);

	scanf("%d", &r);
	while (r --) {
		init();
		scanf("%d %d", &n, &m);
		for (int i=0; i<n; i++)
			scanf("%d", &v[i]);
		for (int i=0, u, v; i<m; i++) {
			scanf("%lld %lld", &u, &v);
			e[v-1][u-1] = e[u-1][v-1] = true;
		}
		if (n == 1) {
			printf("%d 1\n", v[0]);
			continue;
		}
		for (int i=0; i<(1<<n); i++)
			for (int a=0; a<n; a++)
				for (int b=0; b<n; b++) {
					if ((a!=b) && ((1<<b)&i) && ((1<<a)&i) && e[a][b]) {
						for (int c=0; c<n; c++) {
							if (((1<<c)&i) && (a!=c) && (b!=c) && e[b][c] && f[i-(1<<a)][b][c] != -1 && g[i-(1<<a)][b][c] != 0) {
								long long value = f[i-(1<<a)][b][c];
								if (e[a][c]) value += (long long)v[a] * v[b] * v[c];
								if (f[i][a][b] < value) {
									f[i][a][b] = value;
									g[i][a][b] = g[i-(1<<a)][b][c];
								}
								else if (f[i][a][b] == value)
									g[i][a][b] += g[i-(1<<a)][b][c];
							}
						if (count(i) == 2) g[i][a][b] = 1;
						}
						f[i][a][b] += v[a] * v[b];
					}
				}
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) {
				if (ans < f[(1<<n)-1][i][j] && g[(1<<n)-1][i][j] != 0) {
					ans = f[(1<<n)-1][i][j];
					tot = g[(1<<n)-1][i][j];
				}
				else if (ans == f[(1<<n)-1][i][j])
					tot += g[(1<<n)-1][i][j];
			}
		for (int i=0; i<n; i++)
			ans += v[i];
		if (tot == 0) puts("0 0");
		else          printf("%lld %lld\n", ans + 1, tot / 2);
	}

	return 0;
}
