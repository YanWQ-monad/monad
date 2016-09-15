// 1052.cpp
#include <cstdio>

int n,ans=0;
int main() {
	freopen("1052.in","r",stdin);
	freopen("1052.out","w",stdout);
	scanf("%d",&n);
	for	(int i=n;i!=0;i/=10)
		ans+=i%10;
	printf("%d\n",ans);
	return 0;
}
