// 1661.cpp
#include <algorithm>
#include <cstdio>
using std::swap;

const int MAXN = 100010;
int n, q, d[MAXN];
struct NODE { int l, r; long long sum; } tree[MAXN*4];

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].sum = d[left];
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	tree[root].sum = tree[root * 2    ].sum
	               + tree[root * 2 + 1].sum;
}

long long GetSum(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].sum;
	if (t <  tree[now].l || s >  tree[now].r) return 0;
	return GetSum(now * 2, s, t) + GetSum(now * 2 + 1, s, t);
}

int main() {
	freopen("1661.in" , "r", stdin );
	freopen("1661.out", "w", stdout);

	scanf("%d %d", &n, &q);
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
	}
	BuildTree(1, 1, n);

	for (int i=0, a, b; i<q; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		printf("%lld\n", GetSum(1, a, b));
	}


	return 0;
}
