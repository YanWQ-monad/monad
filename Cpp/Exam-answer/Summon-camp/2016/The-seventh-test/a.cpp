// a.cpp
#include <algorithm>
#include <cstdio>
using std::max;

int n,m,a[1024],ans=0;
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0,hungry,sum;i<n;i++) {
		hungry=m;
		sum=0;
		for (int j=i;j<n && hungry;j++)
			if (a[j]<=hungry) {
				hungry -= a[j];
				sum++;
			}
		ans = max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
