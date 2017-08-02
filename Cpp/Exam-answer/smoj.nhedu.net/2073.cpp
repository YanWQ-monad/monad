// 2073.cpp
#include <algorithm>
#include <cstdio>
#include <cmath>
using std::max;
using std::min;

const long long INF  = 0xFFFFFFFFFFFFF;
const int MAXN = 100010;
long long n, sum[MAXN], ans=INF;

int find(const int k) {
	int l=1, r=k+1, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (sum[mid] > sum[k] - sum[mid]) r = mid;
		else                              l = mid;
	}
	return r;
}

int main() {
	freopen("2073.in" , "r", stdin );
	freopen("2073.out", "w", stdout);

	scanf("%lld", &n);
	for (int i=1, l; i<n; i++) {
		scanf("%d", &l);
		sum[i+1] = sum[i] + l;
	}

	for (int i=2; i<=n; i++) {
		int j = find(i);
		if (sum[j] == sum[i]-sum[j]) ans = min(ans, max(sum[j],                      sum[n]-sum[i]));
		else                         ans = min(ans, max(max(sum[j-1],sum[i]-sum[j]), sum[n]-sum[i]));
	}

	printf("%lld\n", ans);

	return 0;
}
