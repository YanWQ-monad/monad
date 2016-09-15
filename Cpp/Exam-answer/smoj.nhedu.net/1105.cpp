// 1105.cpp
#include <algorithm>
#include <cstdio>
using std::min;

int n,m,a,b;
int main() {
	freopen("1105.in","r",stdin);
	freopen("1105.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&a,&b);
	printf("%d\n",min(n,min(m,min(a,b))));
	return 0;
}
