// 1137.cpp
#include <algorithm>
#include <cstdio>
using std::min;

int n,d[50],m,f[1002][1002];
int cmin(int n,int m) {
	if  (n==0)	return m;
	if  (m==0)  return n;
	return min(m,n);
}
int main() {
	freopen("1137.in","r",stdin);
	freopen("1137.out","w",stdout);
	scanf("%d",&n);
	for (int i=1,temp;i<=n;i++) {
		scanf("%d",&temp);
		d[i]=temp;
		f[i][temp]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1,o,p;j<=1000;j++) {
			if  (f[i][j]==1) continue;
			o=p=0;
			if  (f[i-1][j]>0)                o=f[i-1][j];
			if  (j-d[i]>0 && f[i-1][j-d[i]]) p=f[i-1][j-d[i]]+1;
			f[i][j]=cmin(o,p);
		}
	for (int i=1;i<1001;i++)
		printf("%d ",f[n][i]==0? -1:f[n][i]);
	return 0;
}
