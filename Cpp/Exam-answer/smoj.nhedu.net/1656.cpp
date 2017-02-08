// 1656.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::max;
using std::min;

const int INF  = 0x7FFF7FFF;
const int MAXN = 100010;
int n, q, d[MAXN];
struct NODE { int l, r, mi, ma; } tree[MAXN*4];

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].mi = tree[root].ma = d[left];
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	tree[root].ma = max(tree[root * 2    ].ma, tree[root * 2 + 1].ma);
	tree[root].mi = min(tree[root * 2    ].mi, tree[root * 2 + 1].mi);
}

int GetMin(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].mi;
	if (t <  tree[now].l || s >  tree[now].r) return INF;
	return min(GetMin(now * 2, s, t), GetMin(now * 2 + 1, s, t));
}

int GetMax(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].ma;
	if (t <  tree[now].l || s >  tree[now].r) return -INF;
	return max(GetMax(now * 2, s, t), GetMax(now * 2 + 1, s, t));
}


int main() {
	freopen("1656.in" , "r", stdin );
	freopen("1656.out", "w", stdout);

	scanf("%d %d", &n, &q);
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
	}
	BuildTree(1, 1, n);

	for (int i=0, a, b; i<q; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", GetMax(1, a, b) - GetMin(1, a, b));
	}


	return 0;
}
