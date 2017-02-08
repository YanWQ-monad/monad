// 1660.cpp
#include <cstdio>

const int MAXN = 100010;
int n, d[MAXN];
struct NODE { int l, r; long long sum; } tree[MAXN*4];

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].sum = d[left];
		printf("%lld ", tree[root].sum);
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	tree[root].sum = tree[root * 2    ].sum
	               + tree[root * 2 + 1].sum;
	printf("%lld ", tree[root].sum);
}

int main() {
	freopen("1660.in" , "r", stdin );
	freopen("1660.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
	}
	BuildTree(1, 1, n);

	puts("");

	return 0;
}
