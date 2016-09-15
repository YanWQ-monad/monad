// 1203.cpp
#include <cstdio>
int r,n,k,f[16777217];
int main() {
	freopen("1203.in","r",stdin);
	freopen("1203.out","w",stdout);
	for	(int i=1;i<(1<<24);i++) {
		if	(i&1)	f[i]=f[i-1]+1;
		else	f[i]=f[i>>1];
	}
	scanf("%d",&r);
	for	(int t=0;t<r;t++) {
		scanf("%d %d",&n,&k);
		if	(k==0)	{printf("-1\n");continue;}
		for	(int i=n;i<=(1<<24);i++)
			if	(f[i]<=k) {
				printf("%d\n",i-n);
				break;
			}
	}
	return 0;
}
