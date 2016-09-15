// 1067.cpp
#include <cstdio>

int n;
int main() {
	freopen("1067.in","r",stdin);
	freopen("1067.out","w",stdout);
	scanf("%d",&n);
	printf("%d\n",n%2==0? 0:1);
	return 0;
}
