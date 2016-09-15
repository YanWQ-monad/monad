// 1017.cpp
#include <cstdio>

int min,a,b,ans;
int gcd(const int a,const int b) {
	if	(a%b==0)	return b;
	else	return	gcd(b,a%b);
}
int main() {
	freopen("1017.in","r",stdin);
	freopen("1017.out","w",stdout);
	scanf("%d %d",&a,&b);
	min=gcd(a,b);
	ans=double(a)/min*b;
	printf("%d",ans);
	return 0;
}
