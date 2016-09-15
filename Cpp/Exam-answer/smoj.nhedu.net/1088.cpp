// 1088.cpp
#include <cstdio>

int n;
int main() {
	freopen("1088.in","r",stdin);
	freopen("1088.out","w",stdout);
	scanf("%d",&n);
	switch(n) {
		case 0:	 printf("0");   break;
		case 1:	 printf("1");   break;
		case 2:	 printf("2");   break;
		case 3:	 printf("4");   break;
		case 4:	 printf("7");   break;
		case 5:	 printf("13");  break;
		case 6:	 printf("24");  break;
		case 7:	 printf("44");  break;
		case 8:	 printf("81");  break;
		case 9:	 printf("149"); break;
		case 10: printf("274"); break;
	}
	return 0;
}
