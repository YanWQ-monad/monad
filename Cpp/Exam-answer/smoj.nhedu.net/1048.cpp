// 1048.cpp
#include <cstdio>

int n,ans;
int main() {
	freopen("1048.in","r",stdin);
	freopen("1048.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0,temp;scanf("%d",&temp),ans+=temp,i<n-1;i++);
	printf("%d",ans);
	return 0;
}
