// 1504.cpp
#include <algorithm>
#include <cstdio>
#include <cmath>
using std::max;

const int MAXN = 50;
const int MAXL = 1700;
int n, l[MAXN], e[3], sum[MAXN], ans=-1;
bool f[MAXL][MAXL];

double Heron(const double a, const double b, const double c) {
	const double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
	freopen("1504.in" , "r", stdin );
	freopen("1504.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &l[i]);
		sum[i] = sum[i-1] + l[i];  
	}

	f[0][0] = true;
	for (int i=1; i<=n; i++)
		for (int j=sum[i]; j>=0; j--)
			for (int k=sum[i]-j; k>=0; k--) {
				if (k >= l[i]) f[j][k] |= f[j][k-l[i]];
				if (j >= l[i]) f[j][k] |= f[j-l[i]][k];
			}

	for (int i=1; i<sum[n]; i++)
		for (int j=1; j<sum[n]-i; j++)
			if (i + j > sum[n] - i - j && sum[n] - j > j && sum[n] - i > i && f[i][j])
				ans = max(ans, (int)(Heron(i, j, sum[n] - i - j) * 100));

	printf("%d\n", ans);

	return 0;
}
