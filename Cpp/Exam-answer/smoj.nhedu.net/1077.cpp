// 1077.cpp
#include <cstdio>
int n;
int main() {
	freopen("1077.in","r",stdin);
	freopen("1077.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i+=2)
		printf("%d ",i);
	printf("\n");
	return 0;
}
