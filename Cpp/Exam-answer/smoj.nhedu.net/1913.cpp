// 1913.cpp
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

const int MAXN = 55;
int n, map1[MAXN][MAXN], map2[MAXN][MAXN], ans=0;

int main() {
	freopen("1913.in" , "r", stdin );
	freopen("1913.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &map1[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &map2[i][j]);

	for (int x1=1; x1<=n; x1++)
		for (int y1=1; y1<=n; y1++)
			for (int x2=1; x2<=n; x2++)
				for (int y2=1; y2<=n; y2++) {
					int maxx = min(min(n-x1+1, n-y1+1), min(n-x2+1, n-y2+1));
					for (int i=1; i<=maxx; i++) {
						bool OK = true;
						for (int j=0; j<i && OK; j++) {
							if (map1[x1+i-1][y1+j] != map2[x2+i-1][y2+j]) OK = false;
							if (map1[x1+j][y1+i-1] != map2[x2+j][y2+i-1]) OK = false;
						}
						if (OK) ans = max(ans, i);
						else    break;
					}
				}
	printf("%d\n", ans);


	return 0;
}
