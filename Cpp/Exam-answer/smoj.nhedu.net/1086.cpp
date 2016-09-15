// 1086.cpp
#include <cstdio>
int n,ans=10;
int main() {
	freopen("1086.in","r",stdin);
	freopen("1086.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		printf("%d ",ans=ans-i);
	printf("\n");
	return 0;
}
