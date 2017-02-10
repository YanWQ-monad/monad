// 1670.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;

const int MAXN = 100010;
const int MAXY = 40010;

struct CHESS { int x, y, t; } c[MAXN];
struct TREE  { int l, r, s; } tree[MAXY * 4];
int n, my=0, ans[MAXN];

int ChessSort(const CHESS lhs, const CHESS rhs) {
	return (lhs.x != rhs.x)? (lhs.x < rhs.x) : (lhs.y < rhs.y);
}

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

int main() {
	freopen("1670.in" , "r", stdin );
	freopen("1670.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d %d", &c[i].x, &c[i].y);
		c[i].x ++;
		c[i].y ++;
		c[i].t = i;
		my = max(my, c[i].y);
	}
	sort(c, c+n, ChessSort);
	BuildTree(1, 1, my);

	for (int i=0; i<n; i++) {
		ans[c[i].t] = GetSum(1, 1, c[i].y);
		Update(1, c[i].y, 1);
	}

	for (int i=0; i<n; i++)
		printf("%d\n", ans[i]);

	return 0;
}
