// 1055.cpp
#include <cstdio>

int n,ans;
char d[10];
int main() {
	freopen("1055.in","r",stdin);
	freopen("1055.out","w",stdout);
	scanf("%s",d);
	for	(int i=0;i<10;i++)
		if	(d[i]>'0' && d[i]<='9')
			printf("%c",d[i]);
	return 0;
}
