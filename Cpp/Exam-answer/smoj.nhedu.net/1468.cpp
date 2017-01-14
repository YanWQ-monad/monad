// 1468.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int INF = 0x3FFFFFFF;
const int MAXN = 100010;
const int MAXM = 100010;
int n, m, k, tree[MAXN * 4];

void init() {
	scanf("%d %d", &n, &m);
	k = 1;
	while (k < n)
		k <<= 1;
	for (int i=k+n; i<2*k; i++)
		tree[i] = -INF;
	for (int i=1; i<=n; i++)
		scanf("%d", &tree[i+k-1]);
	for (int i=k-1; i; i--)
		tree[i] = max(tree[i*2], tree[i*2+1]);
}

void edit(const int x, const int y) {
	int pos = x + k - 1;
	tree[pos] = y;
	while (pos >>= 1)
		tree[pos] = max(tree[pos*2], tree[pos*2+1]);
}

void work() {
	for (int i=0, flag, x, y; i<m; i++) {
		scanf("%d", &flag);
		if (flag == 2) {
			printf("%d\n", tree[1]);
		}
		else {
			scanf("%d %d", &x, &y);
			edit(x, y);
		}
	}
}

int main() {
	freopen("1468.in" , "r", stdin );
	freopen("1468.out", "w", stdout);
	
	init();
	work();
	
	return 0;
}
