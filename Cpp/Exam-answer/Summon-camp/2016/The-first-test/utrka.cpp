// utrka.cpp
#include <cstdio>
int n;
char temp[25],mxor[25];
int main() {
	freopen("utrka.in","r",stdin);
	freopen("utrka.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n*2-1;i++) {
		scanf("%s",temp);
		for (int j=0;temp[j]!='\0';j++)
			mxor[j]^=temp[j];
	}
	for (int i=0;mxor[i]!='\0';i++)
		printf("%c",mxor[i]);
	return 0;
}
