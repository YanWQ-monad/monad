// 1202.cpp
#include <cstdio>
int r,x,ans;
int main() {
	freopen("1202.in","r",stdin);
	freopen("1202.out","w",stdout);
	scanf("%d",&r);
	for	(int i=0;i<r;i++) {
		ans=0;
		scanf("%d",&x);
		for	(int j=64;j;j/=2)
			if	(x>=j) {
				x-=j;
				ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
