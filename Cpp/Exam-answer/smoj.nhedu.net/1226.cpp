// 1226.cpp
#include <cstring>
#include <cstdio>
const int mod = 777;
int r,c,a[51][51],temp;
bool f[51][51][mod];
int dp() {
	f[1][1][a[1][1]%mod]=true;
	for	(int i=1;i<=r;i++)
		for	(int j=1;j<=c;j++)
			for	(int k=0;k<mod;k++) {
				if	(f[i-1][j][k])	f[i][j][(k+a[i][j])%mod]=true;
				if	(f[i][j-1][k])	f[i][j][(k+a[i][j])%mod]=true;
			}
	for	(int i=mod-1;i;i--)
		if	(f[r][c][i])
			return i;
	return 0;
}
int main() {
	freopen("1226.in","r",stdin);
	freopen("1226.out","w",stdout);
	scanf("%d %d",&r,&c);
	for	(int i=1;i<=r;i++)
		for	(int j=1;j<=c;j++)
			scanf("%d",&a[i][j]);
	printf("%d\n",temp=dp());
	return 0;
}
