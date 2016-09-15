// 1071.cpp
#include <cstdio>
int n,m,mod;
int main() {
	freopen("1071.in","r",stdin);
	freopen("1071.out","w",stdout);
	scanf("%d %d %d",&n,&m,&mod);
	printf("%s\n",n%mod==0 && m%mod==0? "yes":"no");
	return 0;
}
