// 1756.cpp
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;
using std::max;

const int MAXN = 800010;
struct STAT { int h, v, p; } station[MAXN];
struct CMP {
	bool operator()(const STAT &lhs, const STAT &rhs) const {
		return lhs.h > rhs.h;
	}
};
priority_queue<STAT, vector<STAT>, CMP> left, right;
long long vtot[MAXN], ans=0;
int n;

void PushLeft(const STAT stin) {
	for (; !left.empty(); ) {
		if (left.top().h >= stin.h) break;
		vtot[stin.p] += left.top().v;
		left.pop();
	}
	left.push(stin);
}

void PushRight(const STAT stin) {
	while (!right.empty() && right.top().h <= stin.h)
		right.pop();
	if (!right.empty()) {
		STAT cur = right.top();
		vtot[cur.p] += stin.v;
	}
	right.push(stin);
}

int main() {
	freopen("1756.in" , "r", stdin );
	freopen("1756.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d %d", &station[i].h, &station[i].v);
		station[i].p = i;
	}
	
	for (int i=1; i<=n; i++) {
		PushLeft(station[i]);
		PushRight(station[i]);
	}

	for (int i=1; i<=n; i++)
		ans = max(ans, vtot[i]);
	printf("%I64d\n", ans);

	return 0;
}
