// 1108.cpp
#include <cstdio>
int n;
int main() {
	freopen("1108.in","r",stdin);
	freopen("1108.out","w",stdout);
	scanf("%d",&n);
	printf("%s\n",(n%4==0 && n%100!=0)|| n%400==0? "yes":"no");
	return 0;
}
