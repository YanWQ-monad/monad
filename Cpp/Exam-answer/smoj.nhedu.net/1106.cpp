// 1106.cpp
#include <algorithm>
#include <cstdio>
using std::swap;

int n,m,a;
int main() {
	freopen("1106.in","r",stdin);
	freopen("1106.out","w",stdout);
	scanf("%d %d %d",&n,&m,&a);
	if  (n>m)   swap(n,m);
	if  (m>a)   swap(a,m);
	if  (n>m)   swap(n,m);
	printf("%d %d %d",n,m,a);
	return 0;
}
