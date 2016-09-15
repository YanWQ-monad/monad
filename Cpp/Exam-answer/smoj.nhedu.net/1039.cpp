// 1039.cpp
#include <cstdio>

#define mod 10007
int n,m,k,f,ans,c[210][210];
int main() {
	freopen("1039.in","r",stdin);
	freopen("1039.out","w",stdout);
	for (int i=0;i<=205;i++)
		for (int j=0;j<=i;j++)
			c[i][j]=j==0 || j==i? 1:(c[i-1][j-1]+c[i-1][j])%mod;
	scanf("%d %d %d %d",&n,&m,&k,&f);
	for (int i=f;i<=k;i++)
		ans=(ans+(c[m][i]*c[n][k-i])%mod)%mod;
	printf("%d\n",ans);
	return 0;
}
