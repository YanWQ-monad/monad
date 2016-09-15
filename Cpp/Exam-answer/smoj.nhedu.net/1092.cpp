// 1092.cpp
#include <cstdio>

int n,d,ans;
int main() {
	freopen("1092.in","r",stdin);
	freopen("1092.out","w",stdout);
	scanf("%d %d",&n,&d);
	ans=(n%10007+10007-d%10007+1)*2%10007;
	printf("%d",ans<0? 0:ans);
	return 0;
}
