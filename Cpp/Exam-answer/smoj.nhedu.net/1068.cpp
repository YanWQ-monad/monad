// 1068.cpp
#include <cstdio>

int n,m;
int main() {
	freopen("1068.in","r",stdin);
	freopen("1068.out","w",stdout);
	scanf("%d %d",&n,&m);
	printf("%s\n",n%2==m%2? "yes":"no");
	return 0;
}
