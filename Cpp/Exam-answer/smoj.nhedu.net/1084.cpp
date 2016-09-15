// 1084.cpp
#include <cstdio>
int n,ans;
int main() {
	freopen("1084.in","r",stdin);
	freopen("1084.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		printf("%d ",i+1);
	for (int i=n-1;i>0;i--)
		printf("%d ",i);
	printf("\n");
	return 0;
}
