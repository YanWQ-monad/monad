// 1405.cpp
#include <algorithm>
#include <cstdio>
using std::min;
using std::max;

const int INF = 2147483647;
const int MAXN = 3000010;
int x,y,mi=INF,ma=-INF,dis[MAXN];
int soso(long long m) {
	if (m == 1) return 1;
	if (m%2) m = m*3+1;
	else m = m/2;
	if (m<MAXN && dis[m]) return dis[m]+1;
	if (m < MAXN) return (dis[m]=soso(m))+1;
	return soso(m)+1;
}
int main() {
	freopen("1405.in", "r", stdin);
	freopen("1405.out", "w", stdout);
	scanf("%d %d", &x, &y);
	for (int i=x; i<=y; i++)
		if (dis[i])
			mi = min(mi, dis[i]);
		else {
			dis[i] = soso(i);
			mi = min(mi, dis[i]);
			ma = max(ma, dis[i]);	
		}
	printf("%d %d\n", mi, ma);
	return 0;
}
