// 1262.cpp
#include <cstdio>
#define min(x,y) ((x)<(y)? (x):(y))

const int MAXN = 110,MAXM = 50010;
int n,a[MAXN],m,f[MAXM];
void dp() {
	for (int i=1;i<=n;i++)
		for (int k=a[i];k<=m;k++)
			f[k]=min(f[k],f[k-a[i]]+1);
}
int main() {
	freopen("1262.in","r",stdin);
	freopen("1262.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) f[i]=0x3fffffff;
	f[0]=0;
	dp();
	printf("%d\n",f[m]==0x3fffffff? -1:f[m]);
	return 0;
}
