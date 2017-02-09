// 1665.cpp
#include <cstdio>

const int INF  = 0x7FFF7FFF;
const int MAXN = 250010;
int n, m, d[MAXN];
char buf[MAXN];
struct NODE { int l, r, num[10], add, sum; } tree[MAXN*8];

int dating(const int root) {
	int ret = 0;
	static int tmp[10];
	for (int i=0; i<10; i++) tmp[i] = tree[root].num[i];
	for (int i=0; i<10; i++) tree[root].num[(i+tree[root].add)%10] = tmp[i];
	for (int i=0; i<10; i++) ret += tree[root].num[i] * i;
	return ret;
}

void Maintain(const int root) {
	tree[root].sum = tree[root * 2    ].sum
		           + tree[root * 2 + 1].sum;
	for (int i=0; i<10; i++)
		tree[root].num[i] = tree[root * 2    ].num[i]
		                  + tree[root * 2 + 1].num[i];
}

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].sum = d[left];
		tree[root].num[d[left]] ++;
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	Maintain(root);
}

void down(const int root) {
	tree[root].sum = dating(root);
	tree[root * 2    ].add += tree[root].add;
	tree[root * 2 + 1].add += tree[root].add;
	tree[root].add = 0;
}

void Update(const int root, const int s, const int t, const int v) {
	if (t < tree[root].l || s > tree[root].r) return;
	if (s <= tree[root].l && tree[root].r <= t ) {
		tree[root].add += v;
		if (tree[root].l != tree[root].r) down(root);
		else {
			tree[root].sum = dating(root);
			tree[root].add = 0;
			dating(root);
		}
		return;
	}
	if (tree[root].add) down(root);
	Update(root * 2    , s, t, v);
	Update(root * 2 + 1, s, t, v);
	Maintain(root);
}

int GetSum(const int root, const int s, const int t) {
	if (tree[root].add) down(root);
	if (t <  tree[root].l || s >  tree[root].r) return 0;
	if (s <= tree[root].l && t >= tree[root].r) return tree[root].sum;
	return GetSum(root * 2, s, t) + GetSum(root * 2 + 1, s, t);
}

int main() {
	freopen("1665.in" , "r", stdin );
	freopen("1665.out", "w", stdout);

	scanf("%d %d", &n, &m);
	scanf("%s", buf);
	for (int i=1; i<=n; i++)
		d[i] = buf[i-1] - '0';

	BuildTree(1, 1, n);

	for (int i=0, s, t; i<m; i++) {
		scanf("%d %d", &s, &t);
		printf("%d\n", GetSum(1, s, t));
		Update(1, s, t, 1);
	}
	return 0;
}
