// 1079.cpp
#include <cstdio>
int n,m;
int main() {
	freopen("1079.in","r",stdin);
	freopen("1079.out","w",stdout);
	scanf("%d",&n);
	for (int i=n;i<1E8;i=i*n)
		printf("%d ",i);
	printf("\n");
	return 0;
}
