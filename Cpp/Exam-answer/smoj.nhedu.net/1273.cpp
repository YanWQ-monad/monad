// 1273.cpp
#include <cstdio>

int n,m,f[23][23][23],ans=0;
void dp() {
	f[0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
			for (int k=0;k<=j;k++)
				for (int l=0;l<=k;l++)
					f[i][j][k] += f[i-1][j-k][l];
}
int main() {
	freopen("1273.in","r",stdin);
	freopen("1273.out","w",stdout);
	scanf("%d %d",&m,&n);
	dp();
	for (int i=0;i<=m;i++)
		ans += f[n][m][i];
	printf("%d\n",ans);
	return 0;
}
