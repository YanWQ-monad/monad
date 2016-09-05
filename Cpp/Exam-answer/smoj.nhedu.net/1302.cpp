// 1302.cpp
#include <cstdio>

const int MOD = 1000000007;
int n,k,a[1010],f[5010];
int main() {
	freopen("Temp.in","r",stdin);
	freopen("Temp.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=0;i<k;i++)
		scanf("%d",&a[i]);
	f[0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<k;j++)
			if (i>=a[j])
				f[i] = (f[i]+f[i-a[j]])%MOD;
	printf("%d\n",f[n]);
	return 0;
}
