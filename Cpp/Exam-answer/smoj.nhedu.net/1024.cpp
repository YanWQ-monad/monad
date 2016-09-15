#include <cstdio>
#include <algorithm>
using std::sort;

int n,m,mo[52],money,ans;
int comp(const int a,const int b) {
	return a>b;
}
int main() {
	freopen("1024.in","r",stdin);
	freopen("1024.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&mo[i]);
	scanf("%d",&m);
	for (int i=0,temp;i<m;i++) {
		scanf("%d",&temp);
		money+=mo[temp];
	}
	sort(mo,mo+n);
	for (int i=0;i<n && money>=mo[i];i++) {
		money-=mo[i];
		ans++;
	}
	printf("%d",ans);
	return 0;
}
