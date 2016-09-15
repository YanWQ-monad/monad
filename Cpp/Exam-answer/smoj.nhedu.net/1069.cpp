// 1069.cpp
#include <cstdio>
int ans;
int main() {
	freopen("1069.in","r",stdin);
	freopen("1069.out","w",stdout);
	for (int i=0,temp;i<4;i++) {
		scanf("%d",&temp);
		ans+=temp&1;
	}
	printf("%d\n",ans);
	return 0;
}
