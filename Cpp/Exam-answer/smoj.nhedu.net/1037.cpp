// 1037.cpp
#include <cstdio>

#define mod 10007
int n,ans=1,c[30][30];
int main() {
	freopen("1037.in","r",stdin);
	freopen("1037.out","w",stdout);
	for (int i=0;i<=26;i++)
		for (int j=0;j<=i;j++)
			c[i][j]=j==0 || j==i? 1:(c[i-1][j-1]+c[i-1][j])%mod;
	scanf("%d",&n);
	if  (n<9)   {printf("0");return 0;}
	for (int i=1;i<n-4;i++)
		ans=ans*i%mod;
	for (int i=0;i<5;i++)
		ans=ans*(n-4-i)%mod;
	printf("%d",ans);
	return 0;
}
