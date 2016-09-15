// 1064.cpp
#include <cstdio>

int a,b;
int main() {
	freopen("1064.in","r",stdin);
	freopen("1064.out","w",stdout);
	scanf("%d %d",&a,&b);
	printf("%d",a>b? a:b);
	return 0;
}
