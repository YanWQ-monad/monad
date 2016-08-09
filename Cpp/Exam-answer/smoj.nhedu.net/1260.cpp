// 1260.cpp
#include <cstdio>

const int MAXN = 16;
int n,k,s[MAXN];
bool used[MAXN];
void print() {
	for (int i=n-k+1;i<=n && s[i]!=0;i++)
		printf("%d ",s[i]);
	printf("\n");
}
void dfs(int x) {
	for (int i=1;i<=n;i++) {
		if (used[i]) continue;
		if (x!=n-k+1 && (i+s[x-1])%5!=1) continue;
		used[s[x]=i]=true;
		if (x<n) dfs(x+1);
		else print();
		s[x]=0;
		used[i]=false;
	}
}
int main() {
	freopen("1260.in","r",stdin);
	freopen("1260.out","w",stdout);
	scanf("%d %d",&n,&k);
	dfs(n-k+1);
	return 0;
}
