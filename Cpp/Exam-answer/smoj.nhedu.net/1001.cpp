#include <cstdio>
int n;
int main() {
	freopen("1001.in","r",stdin);
	freopen("1001.out","w",stdout);
	scanf("%d",&n);
	n=n/2;
	if	(n%2==1)
		printf("%d",(n/2)*(n/2+1));
	else
		printf("%d",(n/2)*(n/2));
	return 0;
}
