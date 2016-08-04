#include <cstdio>

const int MAXN = 10;
int n,s[MAXN];
bool used[MAXN];
void print() {
	for (int i=1;i<=n && s[i]!=0;i++)
		printf("%d ",s[i]);
	printf("\n");
}
void dfs(int x) {
	for (int i=1;i<=n;i++) {
		if (used[i]) continue;
		used[s[x]=i]=true;
		if (x<n) dfs(x+1);
		else print();
		used[i]=false;
	}
}
int main() {
	scanf("%d",&n);
	dfs(1);
	return 0;
}
