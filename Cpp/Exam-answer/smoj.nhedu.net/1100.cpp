// 1100.cpp
#include <cstdio>
int n,m,a;
int main() {
	freopen("1100.in","r",stdin);
	freopen("1100.out","w",stdout);
	scanf("%d %d %d",&n,&m,&a);
	printf("%s\n",a>=n && a<=m? "in":"out");
	return 0;
}
