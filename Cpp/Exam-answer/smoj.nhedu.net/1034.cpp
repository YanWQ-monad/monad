// 1034.cpp
#include <cstdio>

int n,r,ans=1;
int main() {
	freopen("1034.in","r",stdin);
	freopen("1034.out","w",stdout);
	scanf("%d %d",&n,&r);
	for	(int i=0;i<r;i++)
		ans=ans*(n-i)%10007;
	printf("%d\n",ans);
	return 0;
}
