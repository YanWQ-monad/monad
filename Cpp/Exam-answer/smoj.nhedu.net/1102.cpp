// 1102.cpp
#include <cstdio>
int n,m,a,o,p;
int main() {
	freopen("1102.in","r",stdin);
	freopen("1102.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&m,&o,&p,&a);
	printf("%s\n",(a>=n && a<=m)||(a>=o && a<=p)? "in":"out");
	return 0;
}
