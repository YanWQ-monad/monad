// 1710.cpp
#include <algorithm>
#include <cstdio>

const int MAXN = 55;
const int MOD  = 1000000007;
int r, w, h, k;
long long g[MAXN], f[MAXN][MAXN];

int main() {
	freopen ("1710.in" , "r", stdin );
	freopen ("1710.out", "w", stdout);
	
	scanf("%d", &r);
	while (r --) {
		scanf("%d %d %d", &w, &h, &k);
		g[0] = 1;
		for (int i=1; i<=w; i++) {
			g[i] = 0;
			for (int j=1; j<=k && j<=i; j++)
				g[i] = (g[i] + g[i-j]) % MOD;
		}
		
		for (int i=0; i<MAXN; i++)
			f[0][i] = 1;
		for (int i=1; i<=h; i++)
			for (int j=0; j<=w; j++) {
				f[i][j] = f[i-1][j] * g[j] % MOD;
				for (int l=1; l<=j; l++)
					f[i][j] = (f[i][j] + f[i-1][j-l] * g[j-l] % MOD * f[i][l-1]) % MOD;
			}
		printf("%d\n", (int)(f[h][w] % MOD));
	}

	return 0;
}
