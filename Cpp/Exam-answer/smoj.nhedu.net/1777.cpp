// 1777.cpp
#include <algorithm>
#include <cstdio>

const int MAXN = 13;
int n, m, g[1<<MAXN];
long long f[MAXN][1<<MAXN];

bool check(const int set) {
	int zeros = 0;
	for (int i=0; i<m; i++) {
		if ((1 << i) & set) {
			if (zeros % 2)
				return false;
			zeros = 0;
		}
		else zeros ++;
	}
	return zeros % 2 == 0;
}

int main() {
	freopen("1777.in" , "r", stdin );
	freopen("1777.out", "w", stdout);

	while (scanf("%d %d", &n, &m), n!=0 && m!=0) {
		for (int i=0; i<(1<<MAXN); i++) {
			g[i] = false;
			for (int j=0; j<MAXN; j++)
				f[j][i] = 0;
		}
		for (int i=0; i<(1<<m); i++)
			g[i] = check(i);

		for (int i=0; i<(1<<m); i++)
			f[0][i] = g[i];
		for (int i=1; i<n; i++)
			for (int j=0; j<(1<<m); j++)
				for (int k=0; k<(1<<m); k++)
					if ((k|j)==k && g[k])
						f[i][j] += f[i-1][(~j)&k];

		printf("%lld\n", f[n-1][0]);
	}

	return 0;
}
