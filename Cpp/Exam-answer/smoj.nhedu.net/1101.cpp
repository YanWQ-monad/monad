// 1101.cpp
#include <cstdio>
int n,m,a,o,p;
int main() {
	freopen("1101.in","r",stdin);
	freopen("1101.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&m,&o,&p,&a);
	printf("%s\n",a>=n && a<=m && a>=o && a<=p? "in":"out");
	return 0;
}
