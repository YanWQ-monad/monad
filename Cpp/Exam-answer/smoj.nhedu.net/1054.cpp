#include <cstdio>

int n,ans;
int main() {
	freopen("1054.in","r",stdin);
	freopen("1054.out","w",stdout);
	scanf("%d",&n);n=n*10;
	for	(;n!=0;)
		if	((n=n/10)%10==8)
			ans++;
	printf("%d",ans);
	return 0;
}
