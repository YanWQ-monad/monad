// 1219.cpp
#include <cstdio>
int n,y;
long long x;
int main() {
	freopen("1219.in","r",stdin);
	freopen("1219.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n;i++) {
		scanf("%lld %d",&x,&y);
		printf("%d\n",bool(x&(1LL<<y)));
	}
	return 0;
}
