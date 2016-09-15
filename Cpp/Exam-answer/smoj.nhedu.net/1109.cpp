// 1109.cpp
#include <cstdio>
int n,m;
int main() {
	freopen("1109.in","r",stdin);
	freopen("1109.out","w",stdout);
	scanf("%d %d",&n,&m);
	printf("%d\n",(n%4==0 && n%100!=0)|| n%400==0? 335+m:334+m);
	return 0;
}
