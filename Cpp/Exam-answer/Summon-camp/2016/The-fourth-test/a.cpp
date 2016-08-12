// a.cpp
#include <cstdio>
const int MAXN = 50;
int fibonacci[MAXN+1];
void InitFibonacci() {
	fibonacci[0]=0;
	fibonacci[1]=1;
	for (int i=2;i<=MAXN;i++)
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
}
int main() {
	InitFibonacci();
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int r;
	scanf("%d",&r);
	for (int rt=0,n;rt<r;rt++) {
		scanf("%d",&n);
		if (n==0) puts("1 0");
		else printf("%d %d\n",fibonacci[n-1],fibonacci[n]);
	}
	return 0;
}
