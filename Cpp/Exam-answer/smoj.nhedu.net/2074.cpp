// 2074.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MAXN = 100010;

struct EDGE { int u, v; bool rp; } edge[MAXN];
int n, father[MAXN], nums[MAXN];
long long totrp=0, max_rm=0;
bool exist[MAXN];

int findA(const int root) {
	if (father[root]==root)
		return root;
	else {
		return (father[root]=findA(father[root]));
	}
}

void merge(const int lhs, const int rhs) {
	int l = findA(lhs), r = findA(rhs);
	father[l] = r;
	nums[r] += nums[l];
}

int main() {
	freopen("2074.in" , "r", stdin );
	freopen("2074.out", "w", stdout);

	for (int i=0; i<MAXN; i++) {
		father[i] = i;
		nums[i] = 1;
	}

	scanf("%d", &n);
	for (int i=0, rp; i<n-1; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &rp);
		edge[i].rp = rp;
		if (!edge[i].rp) merge(edge[i].u, edge[i].v);
	}

	for (int i=1; i<=n; i++) {
		int A = findA(i);
		if (exist[A]) continue;
		exist[A] = true;
		totrp += (long long)nums[A] * (nums[A] - 1) / 2;
	}
	totrp = (long long)n * (n - 1) / 2 - totrp;

	for (int i=0; i<n-1; i++)
		if (edge[i].rp)
			max_rm = max(max_rm, (long long)nums[findA(edge[i].u)] * nums[findA(edge[i].v)]);

	printf("%lld\n", totrp - max_rm);

	return 0;
}
