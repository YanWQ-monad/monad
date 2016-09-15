// 1087.cpp
#include <cstdio>
int n,a,b;
int main() {
	freopen("1087.in","r",stdin);
	freopen("1087.out","w",stdout);
	scanf("%d %d %d",&n,&a,&b);
	printf("%d\n",a-(a-b)*(n-1));
	return 0;
}
