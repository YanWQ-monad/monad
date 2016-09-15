// 1099.cpp
#include <cstdio>
int a,b;
int main() {
	freopen("1099.in","r",stdin);
	freopen("1099.out","w",stdout);
	scanf("%d %d",&a,&b);
	printf("%d\n",(a%2==0 && b%2==0) || (a%3==0 && b%3==0)? 1:0);
	return 0;
}
