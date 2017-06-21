// 1869.cpp
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

const int MAXN = 55;
struct RECT { int left, right, bottom, up; } choco[MAXN];
int n, a, b, ans=0;

RECT inc(const RECT lhs, const RECT rhs) {
	return (RECT){
		min(lhs.left  , rhs.left  ),
		max(lhs.right , rhs.right ),
		min(lhs.bottom, rhs.bottom),
		max(lhs.up    , rhs.up    )
	};
}

bool can(const RECT rect) {
	return ((rect.right - rect.left) <= a && (rect.up - rect.bottom) <= b) ||
	       ((rect.right - rect.left) <= b && (rect.up - rect.bottom) <= a);
}

void dfs(const int num, const RECT rect, const int begin) {
	ans = max(ans, num);
	for (int i=begin; i<n; i++) {
		RECT now = inc(rect, choco[i]);
		if (can(now))
			dfs(num+1, now, i+1);
	}
}

int main() {
	freopen("1869.in" , "r", stdin );
	freopen("1869.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d %d %d %d", &choco[i].left, &choco[i].bottom, &choco[i].right, &choco[i].up);
	scanf("%d %d", &a, &b);

	for (int i=0; i<n; i++)
		if (can(choco[i])) {
			dfs(1, choco[i], i+1);
	}

	printf("%d\n", ans);

	return 0;
}
