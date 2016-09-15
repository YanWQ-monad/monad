// 1063.cpp
#include <cstdio>

int a,b,c;
int main() {
	freopen("1063.in","r",stdin);
	freopen("1063.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	printf("%lld",(long long)a*b-c*c);
	return 0;
}
