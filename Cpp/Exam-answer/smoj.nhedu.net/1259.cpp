// 1259.cpp
#include <cstdio>

const int MAXN = 10;
int n,k,s[MAXN],link[MAXN];
void print() {
	for (int i=n-k+1;i<=n && s[i]!=0;i++)
		printf("%d ",s[i]);
	printf("\n");
}
void dfs(int x) {
	for (int il=0,i=link[0];i!=0;il=i,i=link[i]) {
		link[il]=link[i];
		s[x]=i;
		if (x<n) dfs(x+1);
		else print();
		link[il]=i;
		s[x]=0;
	}
}
int main() {
	freopen("1259.in","r",stdin);
	freopen("1259.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++)
		link[i]=i+1;
	dfs(n-k+1);
	return 0;
}
