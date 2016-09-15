// 1083.cpp
#include <cstdio>
int n,ans;
int main() {
	freopen("1083.in","r",stdin);
	freopen("1083.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<1<<n;i<<=1)
		printf("%d ",ans=ans+i);
	printf("\n");
	return 0;
}
