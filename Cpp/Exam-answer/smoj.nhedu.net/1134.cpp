// 1134.cpp
#include <algorithm>
#include <cstdio>
using std::max;

int n,f[1002][1002],m;
int main() {
	freopen("1134.in","r",stdin);
	freopen("1134.out","w",stdout);
	scanf("%d",&n);
	for	(int i=1;i<=n;i++)
		for	(int j=1;j<=i;j++) {
			scanf("%d",&f[i][j]);
			f[i][j]+=max(f[i-1][j],f[i-1][j-1]);
		}
	for	(int i=1;i<=n;i++)
		m=f[n][i]>m? f[n][i]:m;
	printf("%d",m);
	return 0;
}
