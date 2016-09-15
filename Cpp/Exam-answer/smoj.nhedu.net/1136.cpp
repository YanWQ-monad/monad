// 1136.cpp
#include <algorithm>
#include <cstdio>
using std::max;

int n,d[60];
long long f[1002][1002];
int main() {
	freopen("1136.in","r",stdin);
	freopen("1136.out","w",stdout);
	scanf("%d",&n);
	for (int i=1,temp;i<=n;i++) {
		scanf("%d",&temp);
		d[i]=temp;
		f[i][temp]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=1000;j++) {
			if (f[i-1][j])                  f[i][j]+=f[i-1][j];
			if (j-d[i]>0 && f[i-1][j-d[i]]) f[i][j]+=f[i-1][j-d[i]];
		}
	for (int i=1;i<1001;i++)
		printf("%lld ",f[n][i]);
	putchar('\n');
	return 0;
}
