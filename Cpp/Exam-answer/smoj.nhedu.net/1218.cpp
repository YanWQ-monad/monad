// 1218.cpp
#include <cstdio>
int n;
long long x;
int main() {
	freopen("1218.in","r",stdin);
	freopen("1218.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n;i++) {
		scanf("%lld",&x);
		printf("%lld\n",x&(-x));
	}
	return 0;
}
