// 1049.cpp
#include <cstdio>

#define mod 10007
int n,ans;
int main() {
	freopen("1049.in","r",stdin);
	freopen("1049.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,temp;i<n;i++) {
		scanf("%d",&temp);
		ans+=temp>0? temp:0;
	}
	printf("%d\n",ans);
	return 0;
}
