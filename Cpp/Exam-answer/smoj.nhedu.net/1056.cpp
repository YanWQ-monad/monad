// 1056.cpp
#include <cstdio>
int n,a=1,b,ans;
int main() {
	freopen("1056.in","r",stdin);
	freopen("1056.out","w",stdout);
	scanf("%d",&a);
	for (int i=1;b+a<=n;i++) {
		b += a++;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
