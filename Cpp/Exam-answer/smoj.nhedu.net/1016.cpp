#include <cstdio>

int n,a,b;
int main() {
	freopen("1016.in","r",stdin);
	freopen("1016.out","w",stdout);
	scanf("%d %d %d",&n,&a,&b);
	a -= (n-1)%a+1;
	b -= (n-1)%b+1;
	printf("%d",a<b? a:b);
	return 0;
}
