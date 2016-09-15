// 1050.cpp
#include <cstdio>

int n;
long long ans=1;
int main() {
	freopen("1050.in","r",stdin);
	freopen("1050.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,temp;i<n;i++) {
		scanf("%d",&temp);
		ans*=temp;
	}
	printf("%lld\n",ans);
	return 0;
}
