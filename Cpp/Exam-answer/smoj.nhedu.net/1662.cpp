// 1662.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::max;
using std::min;

const int INF  = 0x7FFF7FFF;
const int MAXN = 100010;
int n, q, d[MAXN];
struct NODE { int l, r, ma; } tree[MAXN*4];

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].ma = d[left];
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	tree[root].ma = max(tree[root * 2].ma, tree[root * 2 + 1].ma);
}

void Update(const int root, const int pos, const int value) {
	if (pos < tree[root].l || pos > tree[root].r) return;
	if (tree[root].l == pos  && tree[root].r == pos ) {
		tree[root].ma = value;
		return;
	}
	Update(root * 2    , pos, value);
	Update(root * 2 + 1, pos, value);
	tree[root].ma = max(tree[root * 2].ma, tree[root * 2 + 1].ma);
}

int GetMax(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].ma;
	if (t <  tree[now].l || s >  tree[now].r) return -INF;
	return max(GetMax(now * 2, s, t), GetMax(now * 2 + 1, s, t));
}

int main() {
	freopen("1662.in" , "r", stdin );
	freopen("1662.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
	}
	BuildTree(1, 1, n);

	scanf("%d", &q);
	for (int i=0, flag, a, b; i<q; i++) {
		scanf("%d %d %d", &flag, &a, &b);
		if (flag == 2) {
			if (a > b) swap(a, b);
			printf("%d\n", GetMax(1, a, b));
		}
		else if (flag == 1) {
			Update(1, a, b);
		}
	}

	return 0;
}
