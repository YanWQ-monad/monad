// 1091.cpp
#include <cstdio>

int n;
long long f[51];
int main() {
	freopen("1091.in","r",stdin);
	freopen("1091.out","w",stdout);
	scanf("%d",&n);
	f[0]=f[2]=1;
	for	(int i=4;i<=n;i+=2)
		for	(int j=1;j<i;j+=2)
			f[i]+=f[j-1]*f[i-j-1];
	printf("%lld\n",f[n]);
	return 0;
}
