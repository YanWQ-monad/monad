// 1093.cpp
#include <cstdio>

int n,d,ans;
int main() {
	freopen("1093.in","r",stdin);
	freopen("1093.out","w",stdout);
	scanf("%d %d",&n,&d);
	for	(int i=1;i<=d;i++)
		ans=(ans+(n%10007+10007-i%10007+1)*2)%10007;
	printf("%d",ans<0? 0:ans);
	return 0;
}
