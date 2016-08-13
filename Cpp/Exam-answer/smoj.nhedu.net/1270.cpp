// 1270.cpp
#include <cstdio>

int n,f[1048576];
int main() {
	freopen("1270.in","r",stdin);
	freopen("1270.out","w",stdout);
	scanf("%d",&n);
	f[1]=1;f[2]=2;
	for (int i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	printf("%d\n",f[n]*2);
	return 0;
}
