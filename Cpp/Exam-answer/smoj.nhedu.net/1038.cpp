// 1038.cpp
#include <cstdio>

#define mod 10007
int n,m,k,ans=1;
int main() {
	freopen("1038.in","r",stdin);
	freopen("1038.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<k;i++)
		ans=ans*(n-- * m--)%mod;
	printf("%d",ans);
    return 0;
}
