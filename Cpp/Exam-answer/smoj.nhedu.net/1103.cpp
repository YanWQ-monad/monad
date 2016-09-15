// 1103.cpp
#include <cstdio>
int n,m,a;
int main() {
	freopen("1103.in","r",stdin);
	freopen("1103.out","w",stdout);
	scanf("%d %d %d",&n,&m,&a);
	printf("%d\n",a>(n>m? n:m)? a:(n>m? n:m));
	return 0;
}
