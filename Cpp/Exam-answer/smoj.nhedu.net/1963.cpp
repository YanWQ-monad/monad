// 1963.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::max;
using std::min;

const int INF  = 0xFFFFFFF;
const int MAXN = 131072;

struct NUMBER {
	int max1, max2;
	NUMBER(const int &m1 = -INF, const int &m2 = -INF) {
		max1 = m1;
		max2 = m2;
	}
	NUMBER operator=(const int &p) {
		max1 = p;
		max2 = -INF;
		return *this;
	}
};

NUMBER max(const NUMBER &lhs, const NUMBER &rhs) {
	int p[4] = { lhs.max1, lhs.max2, rhs.max1, rhs.max2 };
	for (int i=4-1; i>=0; i--)
		for (int j=i; j<4-1; j++)
			if (p[j] < p[j+1])
				swap(p[j], p[j+1]);
	NUMBER ret(p[0], p[1]);
	return ret;
}

struct TREE { int l, r; NUMBER num; } tree[MAXN * 4];

void Maintain(const int root) {
	tree[root].num = max(tree[root * 2].num, tree[root * 2 + 1].num);
}

void BuildTree(const int root, const int left, const int right) {
	tree[root].l = left ;
	tree[root].r = right;
	if (left == right)
		return;
	BuildTree(root * 2    ,  left                 , (left + right) / 2);
	BuildTree(root * 2 + 1, (left + right) / 2 + 1,         right     );
	Maintain(root);
}

NUMBER GetMax(const int now, const int s, const int t) {
	if (s <= tree[now].l && t >= tree[now].r) return tree[now].num;
	if (t <  tree[now].l || s >  tree[now].r) return NUMBER();
	return max(GetMax(now * 2, s, t), GetMax(now * 2 + 1, s, t));
}

void Update(const int root, const int pos, const NUMBER value) {
	if (pos < tree[root].l  ||  pos > tree[root].r) return;
	if (pos == tree[root].l && pos == tree[root].r) {
		tree[root].num = value;
		return;
	}
	Update(root * 2    , pos, value);
	Update(root * 2 + 1, pos, value);
	Maintain(root);
}

char com[3];
int n, k;

int main() {
	freopen("1963.in" , "r", stdin );
	freopen("1963.out", "w", stdout);

	scanf("%d", &n);
	BuildTree(1, 1, n);
	for (int i=1, t; i<=n; i++) {
		scanf("%d", &t);
		Update(1, i, t);
	}
	scanf("%d", &k);
	for (int i=0, x, y; i<k; i++) {
		scanf("%s %d %d", com, &x, &y);
		if (com[0] == 'Q') {
			NUMBER num = GetMax(1, x, y);
			printf("%d\n", num.max1 + num.max2);
		}
		else {
			Update(1, x, y);
		}
	}

	return 0;
}
