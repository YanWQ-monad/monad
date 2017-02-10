// 1667.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::max;
using std::min;

const int INF  = 0x7FFF7FFF;
const int MAXN = 80010;
int n, d[MAXN];
long long ans=0;
struct NODE { int l, r, ma; } tree[MAXN*4];

void Maintain(const int root) {
	tree[root].ma = max(tree[root * 2].ma, tree[root * 2 + 1].ma);
}

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].ma = d[left];
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	Maintain(root);
}

int GetMax(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].ma;
	if (t <  tree[now].l || s >  tree[now].r) return -INF;
	return max(GetMax(now * 2, s, t), GetMax(now * 2 + 1, s, t));
}

int find(const int k) {
	int l = k, r = n+1, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (GetMax(1, k+1, mid) < d[k]) l = mid;
		else                            r = mid;
	}
	return l;
}

int main() {
	freopen("1667.in" , "r", stdin );
	freopen("1667.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &d[i]);
	BuildTree(1, 1, n);

	for (int i=1; i<=n; i++) {
		ans += find(i) - i;
	}
	printf("%lld\n", ans);

	return 0;
}
