// 1769.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::sort;

const int MAXN = 50010;
struct PLAYER { int w, x, y; } p[MAXN];
int n;
long long ans=0;

int PlayerSortX(const PLAYER lhs, const PLAYER rhs) {
	return lhs.x < rhs.x;
}
int PlayerSortY(const PLAYER lhs, const PLAYER rhs) {
	return lhs.y < rhs.y;
}

int findX() {
	sort(p, p+n, PlayerSortX);
	int wl=0, wr=0, ret=p[0].x, cur=0;
	long long tot=0, mintot=0;
	for (int i=0; i<=n; i++) {
		wr += p[i].w;
		tot += p[i].w * (p[i].x - p[0].x);
	}
	mintot = tot;
	for (int i=p[0].x; i<=p[n-1].x; i++) {
		if (tot < mintot) {
			mintot = tot;
			ret = i;
		}
		for (; p[cur].x == i; cur++) {
			wl += p[cur].w;
			wr -= p[cur].w;
		}
		tot += wl;
		tot -= wr;
	}
	return ret;
}

int findY() {
	sort(p, p+n, PlayerSortY);
	int wl=0, wr=0, ret=p[0].y, cur=0;
	long long tot=0, mintot=0;
	for (int i=0; i<=n; i++) {
		wr += p[i].w;
		tot += p[i].w * (p[i].y - p[0].y);
	}
	mintot = tot;
	for (int i=p[0].y; i<=p[n-1].y; i++) {
		if (tot < mintot) {
			mintot = tot;
			ret = i;
		}
		for (; p[cur].y == i; cur++) {
			wl += p[cur].w;
			wr -= p[cur].w;
		}
		tot += wl;
		tot -= wr;
	}
	return ret;
}

int main() {
	freopen("1769.in" , "r", stdin );
	freopen("1769.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &p[i].w);
	for (int i=0; i<n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	int ansX = findX();
	int ansY = findY();

	for (int i=0; i<n; i++)
		ans += (long long)(abs(ansX - p[i].x) + abs(ansY - p[i].y)) * p[i].w;
	printf("%lld.00\n", ans);

	return 0;
}
