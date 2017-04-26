// 1421.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::min;

const int INF = 0xFFFFFFF;
const int OFFSET = 100010;
const int MAXN = 100010;

struct FENCE { int l, r; } fence[MAXN];
int n, s, f[MAXN][2], tree[MAXN*8], ans=INF;

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
	freopen("1421.in" , "r", stdin );
	freopen("1421.out", "w", stdout);

	scanf("%d %d", &n, &s);
	s += OFFSET;
	for (int i=n; i; i--) {
		scanf("%d %d", &fence[i].l, &fence[i].r);
		fence[i].l += OFFSET;
		fence[i].r += OFFSET;
	}

	for (int i=0; i<=MAXN; i++)
		f[i][0] = f[i][1] = INF;
	fence[  0].l = fence[  0].r = s;
	fence[n+1].l = fence[n+1].r = OFFSET;
	f[0][0] = f[0][1] = 0;
	for (int i=1, last; i<=n+1; i++) {
		last = GetValue(1, 1, 200020, fence[i].l);
		f[i][0] = min(f[last][0] + abs(fence[i].l - fence[last].l), f[last][1] + abs(fence[i].l - fence[last].r));
		last = GetValue(1, 1, 200020, fence[i].r);
		f[i][1] = min(f[last][0] + abs(fence[i].r - fence[last].l), f[last][1] + abs(fence[i].r - fence[last].r));
		SetQuery(1, 1, 200020, fence[i].l, fence[i].r, i);
	}
	printf("%d\n", f[n+1][0]);

	return 0;
}
