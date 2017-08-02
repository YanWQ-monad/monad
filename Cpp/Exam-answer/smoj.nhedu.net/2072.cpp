// 2072.cpp
#include <cstdio>

const int MOD  = 1000000007;
const int MAXN = 1000010;
long long f[MAXN], g[MAXN];
int n;

int main() {
	freopen("2072.in" , "r", stdin );
	freopen("2072.out", "w", stdout);

	scanf("%d", &n);
	f[1] = g[1] = 2;
	scanf("%*d");
	for (int i=2, p; i<=n; i++) {
		scanf("%d", &p);
		f[i] = (g[i-1] - g[p-1] + MOD + 2) % MOD;
		g[i] = (g[i-1] + f[i  ]          ) % MOD;
	}
	printf("%lld\n", g[n]);

	return 0;
}
