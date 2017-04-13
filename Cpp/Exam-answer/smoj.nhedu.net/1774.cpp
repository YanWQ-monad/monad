// 1774.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 13;
const int MOD  = 1000000000;
int n, m, f[MAXN][1<<MAXN], lim[MAXN], ans=0;

int main() {
	freopen("1774.in" , "r", stdin );
	freopen("1774.out", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i=0, cur; i<n; i++)
		for (int j=0; j<m; j++) {
			scanf("%d", &cur);
			lim[i] = (lim[i] << 1) + cur;
		}

	for (int i=0; i<(1<<m); i++) {
		if ((i | lim[0]) == lim[0] && !(i & (i << 1)))
			f[0][i] = 1;
	}
	//puts("");
	for (int i=1; i<n; i++) {
		for (int j=0; j<(1<<m); j++) {
			if ((lim[i] | j) == lim[i] && !(j & (j << 1)))
				for (int k=0; k<(1<<m); k++)
					if (!(j & k))
						f[i][j] = (f[i][j] + f[i-1][k]) % MOD;
		}
	}

	for (int i=0; i<(1<<m); i++)
		ans = (ans + f[n-1][i]) % MOD;
	printf("%d\n", ans);

	return 0;
}
