// 1664.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::max;
using std::min;

const long long INF  = 0x7FFFFFFFFFF7FFF;
const int MAXN = 100010;
int n, q, d[MAXN];
struct NODE { int l, r; long long sum, mi, ma, add; } tree[MAXN*4];

void maintain(const int root) {
	tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
	tree[root].ma = max(tree[root * 2].ma, tree[root * 2 + 1].ma);
	tree[root].mi = min(tree[root * 2].mi, tree[root * 2 + 1].mi);
}

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].sum = tree[root].mi = tree[root].ma = d[left];
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	maintain(root);
}

void down(const int root) {
	int mid = (tree[root].l + tree[root].r) / 2;
	tree[root * 2    ].add += tree[root].add;
	tree[root * 2 + 1].add += tree[root].add;
	tree[root * 2    ].sum += (mid - tree[root].l + 1) * tree[root].add;
	tree[root * 2 + 1].sum += (tree[root].r - mid    ) * tree[root].add;
	tree[root * 2    ].mi  += tree[root].add;
	tree[root * 2 + 1].mi  += tree[root].add;
	tree[root * 2    ].ma  += tree[root].add;
	tree[root * 2 + 1].ma  += tree[root].add;
	tree[root].add = 0;
}

void UpdatePoint(const int root, const int pos, const int value) {
	if (pos < tree[root].l || pos > tree[root].r) return;
	if (tree[root].l == pos  && tree[root].r == pos ) {
		tree[root].sum = tree[root].mi = tree[root].ma = value;
		return;
	}
	down(root);
	UpdatePoint(root * 2    , pos, value);
	UpdatePoint(root * 2 + 1, pos, value);
	maintain(root);
}

void UpdateChunk(const int root, const int s, const int t, const int v) {
	if (t < tree[root].l || s > tree[root].r) return;
	if (s <= tree[root].l && tree[root].r <= t ) {
		tree[root].add += v;
		tree[root].sum += (tree[root].r - tree[root].l + 1) * v;
		tree[root].mi  += v;
		tree[root].ma  += v;
		return;
	}
	down(root);
	UpdateChunk(root * 2    , s, t, v);
	UpdateChunk(root * 2 + 1, s, t, v);
	maintain(root);
}

long long GetSum(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].sum;
	if (t <  tree[now].l || s >  tree[now].r) return 0;
	down(now);
	return GetSum(now * 2, s, t) + GetSum(now * 2 + 1, s, t);
}

long long GetMin(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].mi;
	if (t <  tree[now].l || s >  tree[now].r) return INF;
	down(now);
	return min(GetMin(now * 2, s, t), GetMin(now * 2 + 1, s, t));
}

long long GetMax(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].ma;
	if (t <  tree[now].l || s >  tree[now].r) return -INF;
	down(now);
	return max(GetMax(now * 2, s, t), GetMax(now * 2 + 1, s, t));
}

int main() {
	freopen("1664.in" , "r", stdin );
	freopen("1664.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
	}
	BuildTree(1, 1, n);

	scanf("%d", &q);
	for (int i=0, flag, s, t, v; i<q; i++) {
		scanf("%d", &flag);
		if (flag == 1) {
			scanf("%d %d %d", &s, &t, &v);
			if (s > t) swap(s, t);
			UpdateChunk(1, s, t, v);
		}
		else if (flag == 2) {
			scanf("%d %d", &s, &t);
			if (s > t) swap(s, t);
			printf("%lld\n", GetSum(1, s, t));
		}
	}

	return 0;
}
