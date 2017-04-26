// 1833.cpp
#include <algorithm>
#include <cstdio>
using std::swap;

const int MAXN = 200010;
int tree[MAXN*4];
int n, m;

void PushDown(const int root, const int l, const int r) {
	if (tree[root] == 0) return;
	tree[root<<1|1] = tree[root<<1] = tree[root];
	tree[root] = 0;
}

void SetQuery(const int root, const int l, const int r, const int s, const int t, const int value) {
	if (s > r  ||  t < l) return;
	if (s <= l && r <= t) {
		tree[root] = value;
	}
	else {
		PushDown(root, l, r);
		SetQuery(root<<1  , l              , (l + r) / 2, s, t, value);
		SetQuery(root<<1|1, (l + r) / 2 + 1, r          , s, t, value);
	}
}

int GetValue(const int root, const int l, const int r, const int pos) {
	if (l == pos && r == pos) {
		return tree[root];
	}
	PushDown(root, l, r);
	if ((l + r) / 2 >= pos) return GetValue(root<<1  , l              , (l + r) / 2, pos);
	if (true              ) return GetValue(root<<1|1, (l + r) / 2 + 1, r          , pos);
}

int main() {
	freopen("1833.in" , "r", stdin );
	freopen("1833.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=0, mode, x, y, z; i<m; i++) {
		scanf("%d", &mode);
		if (mode == 1) {
			scanf("%d %d %d", &x, &y, &z);
			if (x > y) swap(x, y);
			SetQuery(1, 1, n, x, y, z);
		}
		else {
			scanf("%d", &x);
			printf("%d\n", GetValue(1, 1, n, x));
		}
	}

	return 0;
}
