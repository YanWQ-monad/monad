// 1773.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 12;
int n, w[MAXN][MAXN], f[1<<MAXN];

int main() {
	
	freopen("1773.in" , "r", stdin );
	freopen("1773.out", "w", stdout);

	while (scanf("%d", &n), n!=0) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%d", &w[i][j]);
		for (int i=0; i<(1<<n); i++) {
			f[i] = 0;
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++)
					if ((j^k) && ((1<<j)&i) && ((1<<k)&i))
						f[i] = max(f[i], f[i-(1<<k)] + w[j][k]);
		}
		printf("%d\n", f[(1<<n)-1]);
	}

	return 0;
}
