// 1274.cpp
#include <cstdio>

int main() {
	freopen("1274.in","r",stdin);
	freopen("1274.out","w",stdout);
	int n;
	scanf("%d",&n);
	printf("%c\n",n%6==0? '0':'1');
	return 0;
}
