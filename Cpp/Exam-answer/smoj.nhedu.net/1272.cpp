// 1272.cpp
#include <cstdio>

int n,m,plate[15],ans=0;
int A[12][12];
const int fac[10]={1,2,6,24,120,720,5040,40320,362880,3628800};
void init() {
	for (int i=0;i<=10;i++)
		for (int j=0;j<=i;j++)
			A[i][j]= j==0 || j==i? 1:A[i-1][j]+A[i-1][j-1];
}
void count(int last) {
	int sum=1,Less=n;
	for (int i=0;i<last;i++) {
		sum*=A[Less][plate[i]];
		Less-=plate[i];
	}
	ans+=sum;
}
void dfs(int n,int m,int pos) {
	if (n==0 && m==0) {count(pos);return;}
	if (n==0 || m==0) return;
	for (int i=1;i<=n;i++) {
		plate[pos]=i;
		dfs(n-i,m-1,pos+1);
	}
}
int main() {
	freopen("1272.in","r",stdin);
	freopen("1272.out","w",stdout);
	init();
	scanf("%d %d",&n,&m);
	dfs(n,m,0);
	printf("%d\n",ans/fac[m-1]);
	return 0;
}
