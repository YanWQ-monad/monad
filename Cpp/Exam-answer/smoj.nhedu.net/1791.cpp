// 1791.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>

const int MOD  = 1000000007;
const int MAXN = 31;
const int MAXM = 31;
const int MAXK = 9;
int n, m, k, f[MAXN][MAXM][1<<MAXK][MAXK];

int dfs(const int node, const int edges, const int set, const int cur) {
	if (f[node][edges][set][cur] != -1) return f[node][edges][set][cur];
	if (node == 0) return f[node][edges][set][cur] = (edges == 0);
	if (!(set&1)) f[node][edges][set][cur] = dfs(node-1, edges, set>>1, 1);
	else          f[node][edges][set][cur] = 0;
	if (edges > 0)
		for (int i=cur; i<=k && i<node; i++)
			f[node][edges][set][cur] = (f[node][edges][set][cur] + dfs(node, edges-1, set^1^(1<<i), i)) % MOD;
	return f[node][edges][set][cur];
}

int main() {
	freopen("1791.in" , "r", stdin );
	freopen("1791.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<MAXN; i++)
		for (int j=0; j<MAXM; j++)
			for (int k=0; k<1<<MAXK; k++)
				for (int l=0; l<MAXK; l++)
					f[i][j][k][l] = -1;
	printf("%d\n", dfs(n, m, 0, 1));

	return 0;
}
