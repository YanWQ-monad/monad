// 1082.cpp
#include <cstdio>
int n,ans=1;
int main() {
	freopen("1082.in","r",stdin);
	freopen("1082.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n*3;i+=3)
		printf("%d ",ans=ans+i);
	printf("\n");
	return 0;
}
