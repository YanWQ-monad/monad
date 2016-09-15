// 1027.cpp
#include <cstdio>

int n;
bool d[10000];
int main() {
	freopen("1027.in","r",stdin);
	freopen("1027.out","w",stdout);
	scanf("%d",&n);
	for	(int i=1;true;i++) {
		n=n/10%100;
		n=n*n;
		if (d[n])  {printf("%d",i);break;}
		else d[n]=true;
	}
	return 0;
}
