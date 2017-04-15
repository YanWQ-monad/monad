// 1787.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::swap;

const int MAXN = 100010;

struct TREE  { int l, r, s; } tree[MAXN * 4];

void Maintain(const int root) {
	tree[root].s = tree[root * 2].s + tree[root * 2 + 1].s;
}

void BuildTree(const int root, const int l, const int r) {
	tree[root].l = l;
	tree[root].r = r;
	if (l == r) {
		tree[root].s = 0;
		return;
	}
	BuildTree(root * 2    , l              , (l + r) / 2);
	BuildTree(root * 2 + 1, (l + r) / 2 + 1, r          );
	Maintain(root);
}

void Update(const int root, const int pos, const int value) {
	if (pos < tree[root].l  ||  tree[root].r < pos) return;
	if (tree[root].l == pos && tree[root].r == pos) {
		tree[root].s += value;
		return;
	}
	Update(root * 2    , pos, value);
	Update(root * 2 + 1, pos, value);
	Maintain(root);
}

int GetSum(const int root, const int s, const int t) {
	if (t < tree[root].l  ||  tree[root].r < s) return 0;
	if (s <= tree[root].l && tree[root].r <= t) return tree[root].s;
	return GetSum(root * 2, s, t) + GetSum(root * 2 + 1, s, t);
}

int n, m, data[MAXN], tot=0, x, y;

int main() {
	freopen("1787.in" , "r", stdin );
	freopen("1787.out", "w", stdout);

	scanf("%d", &n);
	BuildTree(1, 1, n+10);
	for (int i=0; i<n; i++)
		scanf("%d", &data[i]);
	scanf("%d", &m);
	scanf("%d %d", &x, &y);
	swap(data[x], data[y]);
	for (int i=0; i<n; i++) {
		tot = (tot + GetSum(1, data[i], n+5)) % 2;
		Update(1, data[i], 1);
	}
	printf("%d\n", tot = tot % 2);
	for (int i=0; i<m-1; i++) {
		scanf("%d %d", &x, &y);
		if (x != y) tot = 1 - tot;
		printf("%d\n", tot);
	}

	return 0;
}
