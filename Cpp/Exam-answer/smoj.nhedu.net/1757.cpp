// 1757.cpp
#include <cstdio>
#include <vector>
#include <queue>

const int MAXN = 10010;
std::priority_queue<int, std::vector<int>, std::greater<int> > sands;
int n, m, ans=0;

int Merge(const int num) {
	int ret = 0;
	for (int i=0; i<num; i++) {
		ret += sands.top();
		sands.pop();
	}
	ans += ret;
	return ret;
}

int main() {
	freopen("1757.in" , "r", stdin );
	freopen("1757.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=0, cur; i<n; i++) {
		scanf("%d", &cur);
		sands.push(cur);
	}

	const int first = (n - 2) % (m - 1) + 2;
	sands.push(Merge(first));
	for (; sands.size() > 1; )
		sands.push(Merge(m));
	printf("%d\n", ans);

	return 0;
}
