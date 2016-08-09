// 1263.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
#define max(x,y) ((x)>(y)? (x):(y))

const int MAXN = 10010;
int n,f[MAXN],max;
struct NODE {int x,y;}q[MAXN];
int NodeSort(NODE lhs,NODE rhs) {
	return lhs.y<rhs.y;
}
void dp() {
	for (int i=1;i<=n;i++) {
		f[i]=1;
		for (int j=1;j<i;j++) {
			if (q[j].y>q[i].x) continue;
			f[i]=max(f[i],f[j]+1);
		}
		max=f[i]>max? f[i]:max;
	}
}
int main() {
	freopen("1263.in","r",stdin);
	freopen("1263.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&q[i].x,&q[i].y);
	sort(q+1,q+n+1,NodeSort);
	dp();
	printf("%d\n",max);
	return 0;
}
