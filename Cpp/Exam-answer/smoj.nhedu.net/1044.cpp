// 1044.cpp
#include <cstdio>

int a,b;
int gcd(const int a, const int b) {
	if  (a%b==0) return b;
	else return gcd(b,a%b);
}
int main() {
	freopen("1044.in","r",stdin);
	freopen("1044.out","w",stdout);
	scanf("%d %d",&a,&b);
	printf("%d\n",a*b/gcd(a,b));
    return 0;
}
