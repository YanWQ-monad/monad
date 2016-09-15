// 1053.cpp
#include <cstdio>
int n;
int main() {
	freopen("1053.in","r",stdin);
	freopen("1053.out","w",stdout);
	scanf("%d",&n);
	if  (n==0)  printf("0");
	for (;n%10==0;n=n/10);
	for (int temp;n!=0;) {
		temp=n%10;n=n/10;
		printf("%d",temp);
	}
	return 0;
}
