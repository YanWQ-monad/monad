// 1072.cpp
#include <cstdio>
int n,m,o;
int main() {
	freopen("1072.in","r",stdin);
	freopen("1072.out","w",stdout);
	scanf("%d %d %d",&n,&m,&o);
	printf("%d\n",n%m==0? n/m:n/o);
	return 0;
}
