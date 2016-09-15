// 1179.cpp
#include <cstdio>
int n,m,sum[100001],a,b;
int main() {
	freopen("1179.in","r",stdin);
	freopen("1179.out","w",stdout);
	scanf("%d %d",&n,&m);
	for	(int i=1,temp;i<=n;i++) {
		scanf("%d",&temp);
		sum[i]=sum[i-1]+temp;
	}
	for	(int i=0;i<m;i++) {
		scanf("%d %d",&a,&b);
		if	(a>b) {int temp=a;a=b;b=temp;}
		printf("%d\n",sum[b]-sum[a-1]);
	}
	return 0;
}
