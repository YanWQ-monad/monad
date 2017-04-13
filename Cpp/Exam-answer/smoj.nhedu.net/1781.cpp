// 1781.cpp
#include <algorithm>
#include <cstdio>

const int MAXN = 21;
int n, len[MAXN], sca[MAXN], f[1<<MAXN][2], ap;
bool u[MAXN];

void print() {
	int cur = (1 << n) - 1;
	while (cur >= 0 && f[cur][1] != -1) {
		u[f[cur][1]] = true;
		printf("%d ", f[cur][1]);
		cur = cur - (1 << f[cur][1]);
	}
	for (int i=0; i<n; i++)
		if (!u[i])
			printf("%d ", i);
	puts("");
}

void dfs(const int set, const int value) {
	if (f[set][0] != -1) return;
	if (set == 0) {
		f[set][0] = 0;
	}
	for (int i=0; i<n; i++)
		if (set&(1<<i)) {
			if (value < sca[i]) continue;
			if (value+47 < len[i]) continue;
			dfs(set-(1<<i), value+47-len[i]);
			if (f[set-(1<<i)][0]+1>f[set][0]) {
				f[set][0] = f[set-(1<<i)][0] + 1;
				f[set][1] = i;
			}
		}
}

int main() {
	freopen("1781.in" , "r", stdin );
	freopen("1781.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &len[i]);
	for (int i=0; i<n; i++)
		scanf("%d", &sca[i]);
	for (int i=0; i<(1<<n); i++)
		f[i][0] = f[i][1] = -1;

	dfs((1<<n)-1, 74);

	print();

	return 0;
}
