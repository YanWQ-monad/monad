// 1042.cpp
#include <cstdio>
long long d,t,b,m;
int main() {
	freopen("1042.in","r",stdin);
	freopen("1042.out","w",stdout);
	scanf("%lld",&m);
	for (long long i=0;i<m;i++) {
		scanf("%lld %lld %lld",&d,&t,&b);
		long long l=d-t,n=l/(b-1);
		if  (n*(b-1)==l && n<=t && n>=0)    printf("Possible\n");
		else    printf("Impossible\n");
	}
	return 0;
}
