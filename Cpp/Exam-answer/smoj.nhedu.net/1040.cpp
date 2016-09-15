// 1040.cpp
#include <cstdio>

#define mod 10007
int n,m,c[5010][5010];
int yang(int n,int m) {
	if      (m==0 || m==n)                   return c[n][m]=1;
	else if (n<5000 && m<5000 && c[n][m]!=0) return c[n][m];
	else                                     return c[n][m]=(yang(n-1,m)+yang(n-1,m-1))%mod;
}
int main() {
	freopen("1040.in","r",stdin);
	freopen("1040.out","w",stdout);
	scanf("%d %d",&n,&m);
	printf("%d\n",yang(n+m,m));
	return 0;
}
