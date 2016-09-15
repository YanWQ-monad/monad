// 1167.cpp
#include <cstdio>
int n,c,w[50001],sum[50001],max;
int find(int m) {
	int l=0,r=n,mid;
	while   (l+1<r) {
		mid=(l+r)/2;
		if  (sum[mid]-sum[m-1]<=c)	l=mid;
		else    r=mid;
	}
	return l-m+1;
}
int main() {
	freopen("1167.in","r",stdin);
	freopen("1167.out","w",stdout);
	scanf("%d %d",&n,&c);
	scanf("%d",&w[0]);
	sum[0]=w[0];
	for (int i=1;i<n;i++) {
		scanf("%d",&w[i]);
		sum[i]=sum[i-1]+w[i];
	}
	for (int i=0,temp;i<n;i++) {
		temp=find(i);
		max=temp>max? temp:max;
	}
	printf("%d\n",max);
	return 0;
}
