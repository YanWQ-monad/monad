// 1043.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::swap;

const int MAXN = 1010;
int r, n, d, a[MAXN];
long long p[MAXN];

int main() {
	freopen("1043.in" , "r", stdin );
	freopen("1043.out", "w", stdout);

	scanf("%d", &r);
	while (r --) {
		scanf("%d %d", &n, &d);
		for (int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for (int i=0; i<n; i++) {
			long long cur = a[i];
			for (int j=0; j<i; j++)
				if (abs(p[j] - cur) < d)
					cur = p[j] + d;
			p[i] = cur;
			printf("%lld ", p[i]);
			for (int j=1; j<=i; j++)
				if (p[j-1] > p[j])
					swap(p[j-1], p[j]);
			for (int j=i; j; j--)
				if (p[j-1] > p[j])
					swap(p[j-1], p[j]);
		}
		puts("");
	}

	return 0;
}
