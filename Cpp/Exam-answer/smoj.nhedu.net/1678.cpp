// 1678.cpp
#include <algorithm>
#include <cstdio>
#include <limits>
#include <cmath>
using std::min;

const int MAXN = 205;
const int MAXS = 55;
const double INF = std::numeric_limits<double>::max();
struct NODE { int x, y; } tree[MAXN][MAXS];
int n, s[MAXN];
double ans=INF, f[MAXN][MAXS];

double dis(const NODE lhs, const NODE rhs) {
	return sqrt( (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y) );
}

int main() {
	freopen("1678.in" , "r", stdin );
	freopen("1678.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &s[i]);
		for (int j=0; j<s[i]; j++)
			scanf("%d %d", &tree[i][j].x, &tree[i][j].y);
	}

	for (int i=0; i<s[1]; i++) {
		for (int j=0; j<s[2]; j++)
			f[2][j] = dis(tree[1][i], tree[2][j]);
		for (int j=3; j<=n; j++)
			for (int k=0; k<s[j]; k++) {
				f[j][k] = INF;
				for (int l=0; l<s[j-1]; l++)
					f[j][k] = min(f[j][k], f[j-1][l] + dis(tree[j][k], tree[j-1][l]));
			}
		for (int j=0; j<s[n]; j++)
			ans = min(ans, f[n][j] + dis(tree[n][j], tree[1][i]));
	}

	printf("%d\n", (int)(ans*100));

	return 0;
}
