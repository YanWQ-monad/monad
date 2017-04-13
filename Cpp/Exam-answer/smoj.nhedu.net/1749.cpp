// 1749.cpp
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

const int INF  = 0x6FFFFFFF;
const int MAXN = 150010;
int p, f[MAXN], g[MAXN];

int main() {
	freopen("1749.in" , "r", stdin );
	freopen("1749.out", "w", stdout);
	
	scanf("%d", &p);
		
	for (int i=1, cur; i<=p; i++) {
		scanf("%d", &cur);
		f[i] = max(f[i-1], g[i-1] + cur);
		g[i] = max(g[i-1], f[i-1] - cur);
	}
	
	printf("%d\n", f[p]);
	
	return 0;
}
