// 1699.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 50010;
struct TREE { int l, r, sum; } tree[MAXN*2*4];
int n, color[MAXN*2], link[MAXN], statu[MAXN], ans=0;

void Maintain(const int root) {
	tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right) {
		tree[root].sum = 0;
		return;
	}
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	Maintain(root);
}

int GetSum(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].sum;
	if (t <  tree[now].l || s >  tree[now].r) return 0;
	return GetSum(now * 2, s, t) + GetSum(now * 2 + 1, s, t);
}

void Update(const int root, const int pos, const int value) {
	if (pos < tree[root].l || pos > tree[root].r) return;
	if (tree[root].l == pos  && tree[root].r == pos ) {
		tree[root].sum = value;
		return;
	}
	Update(root * 2    , pos, value);
	Update(root * 2 + 1, pos, value);
	Maintain(root);
}

int main() {
	freopen("1699.in" , "r", stdin );
	freopen("1699.out", "w", stdout);

	scanf("%d", &n);
	BuildTree(1, 1, n*2);
	for (int i=1; i<=n*2; i++) {
		scanf("%d", &color[i]);
		if (!link[color[i]]) link[color[i]] = i;
	}

	for (int i=1; i<=n*2; i++) {
		if (statu[color[i]]) {
			Update(1, link[color[i]], 0);
			ans += GetSum(1, link[color[i]], i);
			continue;
		}
		else statu[color[i]] = 1;
		Update(1, i, 1);
	}
	printf("%d\n", ans);

	return 0;
}
