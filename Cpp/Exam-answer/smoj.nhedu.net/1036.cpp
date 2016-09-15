// 1036.cpp
#include <cstdio>

int l,ans=26;
int main() {
	freopen("1036.in","r",stdin);
	freopen("1036.out","w",stdout);
	scanf("%d",&l);
	for (int i=1;i<l;i++)
		ans=ans*25%10007;
	printf("%d\n",ans);
    return 0;
}
