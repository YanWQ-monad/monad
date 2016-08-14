// 1272.cpp
#include <cstdio>

int n,m,f[12][12],C[12][12];
const int fac[10]={1,2,6,24,120,720,5040,40320,362880,3628800};
void init() {
	for (int i=0;i<=10;i++)
		for (int j=0;j<=i;j++)
			C[i][j]= j==0 || j==i? 1:C[i-1][j]+C[i-1][j-1];
}
void dp() {
	f[0][0]=1;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=j;k++)
				f[i][j] += C[j][k]*f[i-1][j-k];
}
int main() {
	freopen("1272.in","r",stdin);
	freopen("1272.out","w",stdout);
	scanf("%d %d",&n,&m);
	init();
	dp();
	printf("%d\n",f[m][n]/fac[m-1]);
	return 0;
}
