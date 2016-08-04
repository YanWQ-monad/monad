#include <cstdio>

const int MAXN = 16;
int n,ltr[MAXN];
bool line[MAXN],lslash[MAXN*2],rslash[MAXN*2];
void print() {
	for (int i=1;i<=n;i++)
		printf("%d ",ltr[i]);
	printf("\n");
}
void dfs(int now) {
	for (int i=1;i<=n;i++) {
		if (line[i] || lslash[i+now] || rslash[i-now+n]) continue;
		line[i]=lslash[i+now]=rslash[i-now+n]=ltr[now]=i;
		if (now>=n) print();
		else dfs(now+1);
		line[i]=lslash[i+now]=rslash[i-now+n]=false;
	}
}

int main() {
	scanf("%d",&n);
	dfs(1);
	return 0;
}
