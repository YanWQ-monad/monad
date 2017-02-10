// 1668.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::min;

const long long INF  = 0x3FFFFFFFFFFFF;
const int MAXM = 30010;
const int MAXL = 300010;

struct CLEANER { int s, t, w; } c[MAXM];
struct SEGTREE { int l, r; long long m; } tree[MAXL*4];
int m, l, r, s[MAXM], t[MAXM], w[MAXM], maps[MAXL], mapt[MAXL];
long long f[MAXL];

int CleanerSort(const CLEANER lhs, const CLEANER rhs) {
	return (lhs.t != rhs.t)? (lhs.t < rhs.t) : (lhs.s < rhs.s);
}

void Maintain(const int root) {
	tree[root].m = min(tree[root * 2].m, tree[root * 2 + 1].m);
}

void BuildTree(const int root, const int l, const int r) {
	tree[root].l = l;
	tree[root].r = r;
	if (l == r) {
		tree[root].m = INF;
		return;
	}
	BuildTree(root * 2    , l              , (l + r) / 2);
	BuildTree(root * 2 + 1, (l + r) / 2 + 1, r          );
	Maintain(root);
}

void Update(const int root, const int pos, const long long value) {
	if (pos > tree[root].r  ||  pos < tree[root].l) return;
	if (pos == tree[root].l && tree[root].r == pos) {
		tree[root].m = value;
		return;
	}
	Update(root * 2    , pos, value);
	Update(root * 2 + 1, pos, value);
	Maintain(root);
}

long long GetMin(const int root, const int s, const int t) {
	if (s > tree[root].r  ||  t < tree[root].l) return INF;
	if (s <= tree[root].l && tree[root].r <= t) return tree[root].m;
	return min(GetMin(root * 2, s, t), GetMin(root * 2 + 1, s, t));
}

int main() {
	freopen("1668.in" , "r", stdin );
	freopen("1668.out", "w", stdout);

	scanf("%d %d %d", &m, &l, &r);
	r = r - l + 1;
	for (int i=1; i<=m; i++) {
		scanf("%d %d %d", &c[i].s, &c[i].t, &c[i].w);
		c[i].s = c[i].s - l + 1;
		c[i].t = c[i].t - l + 1;
	}
	l = l - l + 1;
	sort(c+1, c+m+1, CleanerSort);
	BuildTree(1, 0, r);
	for (int i=0; i<MAXL; i++) { maps[i] = m + 1; mapt[i] = 0; }
	for (int i=m; i   ; i--)   maps[c[i].t] = i;
	for (int i=1; i<=m; i++)   mapt[c[i].t] = i;

	Update(1, 0, f[0]=0);
	for (int i=1, j; i<=r; i++) {
		f[i] = INF;
		for (j = maps[i]; j <= mapt[i]; j++)
			f[i] = min(f[i], GetMin(1, c[j].s - 1, i - 1) + c[j].w);
		Update(1, i, f[i]);
	}

	printf("%lld\n", f[r] >= INF? -1 : f[r]);



	return 0;
}
