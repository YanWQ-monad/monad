// 1045.cpp
#include <cstdio>

int a,b;
int gcd(const int a, const int b) {
	if  (a%b==0) return b;
	else return gcd(b,a%b);
}
int main() {
	freopen("1045.in","r",stdin);
	freopen("1045.out","w",stdout);
	scanf("%d %d",&a,&b);
	printf("%d\n",gcd(a,b));
    return 0;
}
