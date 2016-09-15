// 1220.cpp
#include <cstdio>
long long n;
int k,w=62,t=0;
int main() {
	freopen("1220.in","r",stdin);
	freopen("1220.out","w",stdout);
	scanf("%lld %d",&n,&k);
	while (t<k) {
		if (n&(1LL<<w)) t++;
		w--;
	}
	w++;
	while (n&(1LL<<w)) w++;
	printf("%lld\n",(1LL<<w)-(n&((1LL<<w)-1)));
	return 0;
}
