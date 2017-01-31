// 1643.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;

const int MAXN = 50010;
int n, k, a[MAXN], f[MAXN], sum[MAXN], ans=0;

int main() {
	freopen("1643.in" , "r", stdin );
	freopen("1643.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);

	sort(a, a+n);
	for (int l=0, r=0; l<n; l++) {
		while (r < n && a[r] - a[l] <= k)
			r ++;
		f[l] = r - 1;
	}

	for (int i=n-1; i>=0; i--)
		sum[i] = max(sum[i+1], f[i] - i + 1);
	for (int i=0; i<n; i++)
		ans = max(ans, (f[i] - i + 1) + sum[f[i] + 1]);
	
	printf("%d\n", ans);

	return 0;
}
