// 1094.cpp
#include <cstdio>

#define mod 1000000007
int n,k,d,ans=1,c;
int main() {
	freopen("1094.in","r",stdin);
	freopen("1094.out","w",stdout);
	scanf("%d %d %d",&n,&k,&d);
	c = int((long long)(k%mod)*(k-1)%mod);
	for	(int i=1;i<k-1;i++)
		c = int((long long)c*(d-i)%mod);
	ans = int(((long long)ans*c%mod)*(n-d+1)%mod);
	printf("%d",ans);
	return 0;
}
