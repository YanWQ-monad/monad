// 1076.cpp
#include <cstdio>
int n,m;
int main() {
	freopen("1076.in","r",stdin);
	freopen("1076.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=n-m;i<n;i++)
		printf("%d ",i);
	printf("\n");
	return 0;
}
