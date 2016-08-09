// 1261.cpp
#include <cstdio>

const int MAXN = 20;
int n,m,s,a[MAXN],ans=0;
void dfs(int pos,int m,int sum) {
	if (m==0) {
		if (sum==s) ans++;
		return;
	}
	if (pos>=n) return;
	dfs(pos+1,m-1,sum+a[pos]);
	dfs(pos+1,m,sum);
}
int main() {
	freopen("1261.in","r",stdin);
	freopen("1261.out","w",stdout);
	scanf("%d %d %d",&n,&m,&s);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(0,m,0);
	printf("%d\n",ans);
	return 0;
}
