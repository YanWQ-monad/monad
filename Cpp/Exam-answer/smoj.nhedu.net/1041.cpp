// 1041.cpp
#include <cstdio>

#define mod 1000000007
int n,m,c[2001][2001];
int pow(const int a,const int n) {
	int ans=1;
	for (int i=0;i<n;i++)
		ans = int((long long)ans*a%mod);
	return ans;
}
int main() {
	freopen("1041.in","r",stdin);
	freopen("1041.out","w",stdout);
	for (int i=0;i<=2000;i++)
		for (int j=0;j<=i;j++)
			c[i][j] = (j==0 || j==i)? 1:(c[i-1][j-1]+c[i-1][j])%mod;
	scanf("%d %d",&n,&m);
	printf("%d\n",int((long long)c[n][n-m]*pow(2,n-m)%mod));
	return 0;
}
