// 1725.cpp
#include <algorithm>
#include <cstdio>
using std::max;

//#define max(a, b) ((a)>(b)? (a):(b))

template<int MAXL>
class mSegentTree {
 private:
	struct TREE { int max; } tree[MAXL * 4];

 public:
	mSegentTree() {}
	void Maintain(const int root) {
		tree[root].max = max(tree[root * 2].max, tree[root * 2 + 1].max);
	}
	void BuildTree(const int root, const int l, const int r) {
		if (l == r) {
			tree[root].max = 0;
			return;
		}
		BuildTree(root * 2    , l              , (l + r) / 2);
		BuildTree(root * 2 + 1, (l + r) / 2 + 1, r          );
		Maintain(root);
	}
	void Update(const int root, const int pos, const int value, const int l, const int r) {
		if (pos < l  ||  pos > r) return;
		if (pos == l && pos == r) {
			tree[root].max = value;
			return;
		}
		Update(root * 2    , pos, value, l              , (l + r) / 2);
		Update(root * 2 + 1, pos, value, (l + r) / 2 + 1, r          );
		Maintain(root);
	}
	int GetMax(const int root, const int s, const int t, const int l, const int r) {
		if (t < l  ||  s > r) return 0;
		if (s <= l && r <= t) return tree[root].max;
		return max(GetMax(root * 2    , s, t, l              , (l + r) / 2),
			       GetMax(root * 2 + 1, s, t, (l + r) / 2 + 1, r          ));
	}
};

const int MAXN = 2010;
int n, d, m, a[MAXN], b[MAXN], f[MAXN][MAXN], ans=0;
mSegentTree<MAXN> tree[MAXN];

int BinarySearch(const int value) {
	int l=-1, r=n, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (b[mid] >= value) r = mid;
		else                 l = mid;
	}
	return r;
}

int main() {
	freopen("1725.in" , "r", stdin );
	freopen("1725.out", "w", stdout);

	scanf("%d %d %d", &n, &d, &m);
	for (int i=1; i<=n; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (int i=0; i<=m; i++)
		tree[i].BuildTree(1, 1, n);

	f[1][0] = a[1];
	tree[0].Update(1, 1, a[1], 1, n);
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			f[i][j] = tree[j-1].GetMax(1, BinarySearch(b[i]-d), i-1, 1, n) + a[i];
			tree[j].Update(1, i, f[i][j], 1, n);
		}
	}

	for (int i=1; i<=n; i++)
		ans = max(ans, f[i][m]);
	printf("%d\n", ans);

	return 0;
}
