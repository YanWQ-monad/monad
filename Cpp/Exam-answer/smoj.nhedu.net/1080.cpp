// 1080.cpp
#include <cstdio>
int n,m,o;
int main() {
	freopen("1080.in","r",stdin);
	freopen("1080.out","w",stdout);
	scanf("%d %d %d",&n,&m,&o);
	printf("%d\n",n+m*(o-1));
	return 0;
}
