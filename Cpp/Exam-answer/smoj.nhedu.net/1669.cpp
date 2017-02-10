// 1669.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;

template<int MAXL>
class mSegentTree {
 public:
	struct TREE { int l, r; long long sum; } tree[MAXL * 4];

	mSegentTree() {}
	void Maintain(const int root) {
		tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
	}
	void BuildTree(const int root, const int l, const int r, const int *arrs = NULL, const int defaul = 0) {
		tree[root].l = l;
		tree[root].r = r;
		if (l == r) {
			if (arrs) tree[root].sum = arrs[l];
			else      tree[root].sum = defaul;
			return;
		}
		BuildTree(root * 2    , l              , (l + r) / 2);
		BuildTree(root * 2 + 1, (l + r) / 2 + 1, r          );
		Maintain(root);
	}
	void Update(const int root, const int pos, const int value) {
		if (pos < tree[root].l  ||  pos > tree[root].r) return;
		if (pos == tree[root].l && pos == tree[root].r) {
			tree[root].sum += value;
			return;
		}
		Update(root * 2    , pos, value);
		Update(root * 2 + 1, pos, value);
		Maintain(root);
	}
	long long GetSum(const int root, const int s, const int t) {
		if (t < tree[root].l  ||  s > tree[root].r) return 0LL;
		if (s <= tree[root].l && tree[root].r <= t) return tree[root].sum;
		return GetSum(root * 2, s, t) + GetSum(root * 2 + 1, s, t);
	}
};

const int MAXN = 200010;
const int MAXX = 20010;

mSegentTree<MAXX> stre, xtre;
struct D_BOOM { int s, x; } d[MAXN];
int n, s[MAXN], x[MAXN], ms=0;
long long ans = 0;

int DBoomSort(const D_BOOM lhs, const D_BOOM rhs) {
	return (lhs.s != rhs.s)? (lhs.s < rhs.s) : (lhs.x < rhs.x);
}

int main() {
	freopen("1669.in" , "r", stdin );
	freopen("1669.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d %d", &d[i].s, &d[i].x);
		ms = max(ms, d[i].x);
	}
	sort(d+1, d+n+1, DBoomSort);

	stre.BuildTree(1, 1, ms, NULL, 0);
	xtre.BuildTree(1, 1, ms, NULL, 0);
	for (int i=1; i<=n; i++) {
		ans += d[i].s * ((xtre.GetSum(1, 1, d[i].x-1) * d[i].x - stre.GetSum(1, 1, d[i].x-1))
		               + (stre.GetSum(1, d[i].x, ms) - xtre.GetSum(1, d[i].x, ms) * d[i].x));
		stre.Update(1, d[i].x, d[i].x);
		xtre.Update(1, d[i].x, 1);
	}
	printf("%I64d\n", ans);

	return 0;
}
