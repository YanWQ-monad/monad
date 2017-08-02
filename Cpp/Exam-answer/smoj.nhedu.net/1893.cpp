// 1893.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::min;

const int MAXN = 410;
int n, k, star[MAXN][MAXN], f[MAXN][MAXN], ans=0xFFFFFFF;

int Get(const int l, const int r, const int u, const int b) {
	return f[r][b] - f[l-1][b] - f[r][u-1] + f[l-1][u-1];
}

int find(const int left, const int right, const int up) {
	int l=up-1, r=n, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (Get(left, right, up, mid) >= k) r = mid;
		else                                l = mid;
	}
	return r;
}

int main() {
	freopen("1893.in" , "r", stdin );
	freopen("1893.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i=0, x, y; i<n; i++) {
		scanf("%d %d", &x, &y);
		star[x][y] ++;
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + star[i][j];

	for (int l=1; l<=n && Get(l, n, 1, n) >= k; l++)
		for (int r=n; r>=l && Get(l, r, 1, n) >= k; r--)
			for (int u=1; u<=n && Get(l, r, u, n) >= k; u++) {
				int b = find(l, r, u);
				if (Get(l, r, u, b) >= k)
					ans = min(ans, (r - l + 1) * (b - u + 1));
			}

	printf("%d\n", ans);
	
	return 0;
}
// https://drive.google.com/file/d/0B85K_c7mx3QjUnZuaFRPWlBIcXM
