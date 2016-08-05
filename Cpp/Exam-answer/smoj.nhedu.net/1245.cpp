// 1245.cpp
#include <cstdio>

void print(int n) {
	if (!n) return;
	printf("%d",n);
	print(n-1);
	printf("%d",n);
}

int main() {
	freopen("1245.in","r",stdin);
	freopen("1245.out","w",stdout);
	int n;
	scanf("%d",&n);
	print(n);
	return 0;
}
