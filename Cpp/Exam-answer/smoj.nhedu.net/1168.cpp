// 1168.cpp
#include <cstdio>
int n;
long long ans=1,now=1;
int main() {
	freopen("1168.in","r",stdin);
	freopen("1168.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n-1;i++,now*=10)
		ans=ans*10+now*9;
	printf("%lld",ans);
	return 0;
}
