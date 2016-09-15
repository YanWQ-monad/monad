// 1098.cpp
#include <cstdio>
int n;
int main() {
	freopen("1098.in","r",stdin);
	freopen("1098.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,temp;i<n;i++) {
		scanf("%d",&temp);
		if  (temp%10==1 || temp%10==2 || temp/10==1 || temp/10==2)
			printf("%d ",temp);
	}
	return 0;
}
