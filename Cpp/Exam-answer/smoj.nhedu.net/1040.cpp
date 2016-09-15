// 1040.cpp
#include <cstdio>

#define mod 10007
int n,m,c[2010][1010];
int main() {
	freopen("1040.in","r",stdin);
	freopen("1040.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<=n+m;i++)
		for (int j=0;j<=i;j++)
			c[i][j]=(j==0||j==i)? 1:(c[i-1][j-1]+c[i-1][j])%mod;
	printf("%d\n",c[n+m][m]);
	return 0;
}
