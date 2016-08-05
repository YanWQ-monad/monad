// 1241.cpp
#include <cstdio>
void bit(int n) {
	if (n>1) bit(n/2);
	printf("%d",n%2);
}

int main() {
	freopen("1241.in","r",stdin);
	freopen("1241.out","w",stdout);
	int n;
	scanf("%d",&n);
	bit(n);
	return 0;
}
