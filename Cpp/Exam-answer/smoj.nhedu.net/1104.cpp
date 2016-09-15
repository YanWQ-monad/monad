// 1104.cpp
#include <algorithm>
#include <cstdio>
using std::swap;

int n,m,a;
int main() {
	freopen("1104.in","r",stdin);
	freopen("1104.out","w",stdout);
	scanf("%d %d %d",&n,&m,&a);
	if  (n<m) swap(n,m);
	if  (m<a) swap(a,m);
	if  (n<m) swap(n,m);
	printf("%d %d %d",n,m,a);
	return 0;
}
