// 1252.cpp
#include <algorithm>
//#include <cstring>
#include <cstdio>
#include <map>
using std::sort;
using std::map;

#define min(x,y) ((x)<(y)? (x):(y))

map<int,int>p;
const int MAXN = 5010;
int n,k,sum=0,a[MAXN],b[MAXN],f[MAXN][3];

void doit() {
	int d=n/k;
	for (int i=0;i<d;i++)
		for (int j=0;j<k;j++)
			p[a[i*k+j+1]]=i;
	for (int i=1;i<=n;i++)
		f[i][0]=p[b[i]];
}
int search(int l,int r,int d) {
	int mid;
	while (l<=r) {
		mid=l+(r-l)/2;
		if (f[mid][2]<=d) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int dp() {
	int _max=0;
	for (int i=1;i<=n;i++) {
		f[i][1]=search(1,i,f[i][0]);
		f[f[i][1]][2]=min(f[f[i][1]][2],f[i][0]);
		_max=f[i][1]>_max? f[i][1]:_max;
	}
	return _max;
}
int main() {
	freopen("1252.in","r",stdin);
	freopen("1252.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		f[i][0]=b[i]=a[i];
		f[i][2]=0xFFFF;
	}
	sort(a+1,a+n+1);
	doit();
	printf("%d\n",n-dp());
	return 0;
}
