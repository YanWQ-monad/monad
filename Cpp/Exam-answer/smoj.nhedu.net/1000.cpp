#include <cstdio>
int n;
int main() {
	freopen("1000.in","r",stdin);
	freopen("1000.out","w",stdout);
	scanf("%d",&n);
	printf("%d",(n-1)%100+1);
	return 0;
}
