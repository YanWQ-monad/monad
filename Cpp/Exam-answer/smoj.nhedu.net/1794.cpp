// 1794.cpp
#include <cstdio>

const int MAXN = 31;
int n, value[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

void PreOrder(const int l, const int r) {
	if (l > r) return;
	printf("%d ", g[l][r]+1);
	PreOrder(l        , g[l][r]-1);
	PreOrder(g[l][r]+1, r        );
}

int main() {
	freopen("1794.in" , "r", stdin );
	freopen("1794.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &value[i]);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			g[i][j] = -1;

	for (int i=0; i<=n; i++)  // len
		for (int j=0; j<n-i; j++)  // start point
			for (int k=j; k<=j+i; k++) { // root 
				int curv = 0;
				if      (j > k-1 && k+1 > i+j) curv = 0;
				else if (j > k-1 || k+1 > i+j) curv = f[j][k-1] + f[k+1][i+j];
				else                           curv = f[j][k-1] * f[k+1][i+j];
				if (curv + value[k] > f[j][i+j]) {
					f[j][i+j] = curv + value[k];
					g[j][i+j] = k;
				}
			}

	printf("%d\n", f[0][n-1]);
	PreOrder(0, n-1);
	puts("");

	return 0;
}
