// 1059.cpp
#include <cstdio>

int n,ans;
int main() {
	freopen("1059.in","r",stdin);
	freopen("1059.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n;i++)
		ans=(ans+1)*2;
	printf("%d",ans);
	return 0;
}
