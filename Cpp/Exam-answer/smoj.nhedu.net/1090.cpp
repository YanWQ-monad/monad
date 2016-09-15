// 1090.cpp
#include <cstdio>

int n,f[1001];
int main() {
	freopen("1090.in","r",stdin);
	freopen("1090.out","w",stdout);
	scanf("%d",&n);
	f[f[0]=1]=3;
	for	(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])*2%10007;	
	printf("%d",f[n]);
	return 0;
}
