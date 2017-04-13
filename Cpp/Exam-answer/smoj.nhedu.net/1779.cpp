// 1779.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::min;

const int INF  = 0x5FFFFFFF;
const int MAXN = 11;
int n, m, lim[MAXN], f[MAXN][1<<MAXN], ans=INF;
char tmp[MAXN+5];

int count(const int value) {
	int ret = 0;
	for (int i=0; i<MAXN; i++)
		ret += ((value & (1<<i)) > 0);
	return ret;
}

int count_h(const int value) {
	int ret = 0;
	for (int i=0, cur=0; i<MAXN; i++) {
		if (((value & (1<<i)) > 0) != cur) {
			if (value & (1<<i))
				ret ++;
			cur = !cur;
		}
	}
	return ret;
}

int main() {
	freopen("1779.in" , "r", stdin );
	freopen("1779.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		scanf("%s", tmp);
		for (int j=0; j<m; j++)
			lim[i] = (lim[i] << 1) + (tmp[j] == '.');
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<(1<<m); j++)
			f[i][j] = INF;

	for (int i=0; i<(1<<m); i++)
		if ((i | lim[0]) == lim[0]) {
			f[0][i] = count_h((~i) & lim[0]) + count(i);
		}
	for (int i=1; i<n; i++)
		for (int j=0; j<(1<<m); j++)
			if ((j | lim[i]) == lim[i]) {
				int hors = count_h((~j) & lim[i]);
				int vers = count(j);
				for (int k=0; k<(1<<m); k++)
					if ((k | lim[i-1]) == lim[i-1])
						f[i][j] = min(f[i][j], f[i-1][k] + (vers - count(k & j)) + hors);
			}

	for (int i=0; i<(1<<m); i++)
		ans = min(ans, f[n-1][i]);
	printf("%d\n", ans);

	return 0;
}
