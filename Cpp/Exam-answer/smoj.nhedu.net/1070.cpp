// 1070.cpp
#include <cstdio>
int n,m;
int main() {
	freopen("1070.in","r",stdin);
	freopen("1070.out","w",stdout);
	scanf("%d %d",&n,&m);
	printf("%s\n",m%n==0? "yes":"no");
	return 0;
}
