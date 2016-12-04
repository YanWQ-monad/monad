#include <cstring>
#include <cstdio>

const int MAXK = 110;
const int MAXN = 1010;
const int MAXM = 10010;
struct EDGE {int t, n;} edge[MAXM];
int k, n, m, cow[MAXK], head[MAXN], can[MAXN], ans;
int add(const int a, const int b) {
	static int cur = 0;
	edge[cur].t = b;
	edge[cur].n = head[a];
	head[a] = cur;
	return ++cur;
}
int d[MAXN], f[MAXN], s[MAXN], curTime;
int dfs(const int start) {
	s[start] = 1;
	d[start] = ++ curTime;
	can[start] ++;
	for (int i=head[start]; i!=-1; i=edge[i].n) {
		if (s[edge[i].t] != 0) continue;
		dfs(edge[i].t);
	}
	s[start] = 2;
	f[start] = ++ curTime;
}
int main() {
	freopen("1528.in", "r", stdin);
	freopen("1528.out", "w", stdout);
	scanf("%d %d %d", &k, &n, &m);
	for (int i=0; i<k; i++)
		scanf("%d", &cow[i]);
	for (int i=0; i<MAXN; i++)
		head[i] = -1;
	for (int i=0, a, b; i<m; i++) {
		scanf("%d %d", &a, &b);
		add(a, b);
	}
	for (int i=0; i<k; i++) {
		curTime = 0;
		memset(s, 0, sizeof(s));
		dfs(cow[i]);
	}
	for (int i=1; i<=n; i++)
		if (can[i] >= k)
			ans ++;
	printf("%d\n", ans);
	return 0;
}
