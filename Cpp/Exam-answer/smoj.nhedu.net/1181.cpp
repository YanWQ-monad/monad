// 1181.cpp
#include <cstdio>
int n,sum[100001],ans=0,mod[7];
int main() {
	freopen("1181.in","r",stdin);
	freopen("1181.out","w",stdout);
	scanf("%d",&n);
	mod[0]=1;
	for	(int i=1,temp;i<=n;i++) {
		scanf("%d",&temp);
		sum[i]=sum[i-1]+temp;
		ans+=mod[sum[i]%7];
		mod[sum[i]%7]++;
	}
	printf("%d\n",ans);
	return 0;
}
