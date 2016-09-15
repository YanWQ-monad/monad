// 1081.cpp
#include <cstdio>
int n,m,o;
int main() {
	freopen("1081.in","r",stdin);
	freopen("1081.out","w",stdout);
	scanf("%d",&n);
	printf("%d\n",n*(n-1)/2+1);
	return 0;
}
