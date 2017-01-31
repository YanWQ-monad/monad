// 1638.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::max;

const int MAXN = 210;
int n, x[MAXN], y[MAXN], p[MAXN], q[MAXN], ans=0;
bool v[MAXN];

bool GGDL(const int x, const int y, const int r) {
	return (x * x + y * y) <= (r * r);
}

int main() {
	freopen("1638.in" , "r", stdin );
	freopen("1638.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d %d %d", &x[i], &y[i], &p[i]);

	for (int i=0, h, t; i<n; i++) {
		memset(v, 0, sizeof(v));
		q[h = t = 0] = i;
		v[i] = true;
		t ++;
		for (; h != t; h ++)
			for (int j=0, node=q[h]; j<n; j++)
				if (!v[j] && GGDL(x[node] - x[j], y[node] - y[j], p[node])) {
					q[t ++] = j;
					v[j] = true;
				}
		ans = max(ans, t);
	}

	printf("%d\n", ans);

	return 0;
}
