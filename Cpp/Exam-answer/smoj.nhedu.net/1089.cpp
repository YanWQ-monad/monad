// 1089.cpp
#include <cstdio>

int m,n,d[101][101],ans[101][101];
int main() {
	freopen("1089.in","r",stdin);
	freopen("1089.out","w",stdout);
	scanf("%d %d",&m,&n);
	for	(int i=0;i<m;i++)
		for	(int j=0;j<n;j++)
			scanf("%d",&d[i][j]);
	ans[0][0]=1;
	for	(int i=1;i<m;i++)
		if	(!d[i][0])
			ans[i][0]=ans[i-1][0];
	for	(int i=1;i<n;i++)
		if	(!d[0][i])
			ans[0][i]=ans[0][i-1];
	for	(int i=1;i<m;i++)
		for	(int j=1;j<n;j++)
			if	(!d[i][j])
				ans[i][j]=ans[i][j-1]+ans[i-1][j];
	printf("%d",ans[m-1][n-1]);
	return 0;
}
