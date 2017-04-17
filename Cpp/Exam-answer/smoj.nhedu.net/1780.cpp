// 1780.cpp
#include <functional>
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 52;
const int MOD  = 1234567891;
int r, n, k, h[MAXN];
unsigned f[MAXN][MAXN][MAXN], ans=0;

int main() {
	freopen("1780.in" , "r", stdin );
	freopen("1780.out", "w", stdout);

	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &n, &k);
		for (int i=1; i<=n; i++)
			scanf("%d", &h[i]);
		sort(h+1, h+n+1, std::greater<int>());
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				for (int k=1; k<=n; k++)
					f[i][j][k] = 0;

		f[1][1][1] = 1;
		for (int i=2; i<=n; i++)
			for (int a=1; a<=i; a++)
				for (int b=1; b<=i; b++) {
					if (h[b]-h[i] <= k) f[i][a][i] = (f[i][a][i] + f[i-1][a][b]) % MOD;
					if (h[a]-h[i] <= k) f[i][i][b] = (f[i][i][b] + f[i-1][a][b]) % MOD;
				}

		ans = 0;
		for (int i=2; i<=n; i++)
			ans = ((ans + f[n][i][n]) % MOD + f[n][n][i]) % MOD;
		printf("%d\n", ans);
	}

	return 0;
}
