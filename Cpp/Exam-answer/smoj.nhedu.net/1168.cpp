// 1168.cpp
#include <cstdio>
int n;
long long ans=1,f1=1,f2=1;
long long pow_ten(int n) {
	long long ans=1;
	for	(int i=0;i<n;i++)
		ans*=10;
	return ans;
}
int main() {
	freopen("1168.in","r",stdin);
	freopen("1168.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n-1;i++)
		ans=ans*10+pow_ten(i)*9;
	printf("%lld",ans);
	return 0;
}
