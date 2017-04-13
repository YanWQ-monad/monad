// 1748.cpp
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 10010;
int n, p[MAXN];
long long cur=0, ans=0;

int main() {
	freopen("1748.in" , "r", stdin );
	freopen("1748.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &p[i]);
	sort(p, p+n);
	
	for (int i=0; i<n; i++) {
		ans += ((long long)p[i] * i) - cur;
		cur += p[i];
	}
	
	printf("%lld\n", ans * 2);
	
	return 0;
}
