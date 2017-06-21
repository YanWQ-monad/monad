// 1866.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;

const int MAXK = 50010;
struct STREET { int p, l; } street[MAXK];
int n, k, maxx=0, ans=0;

int StreetSort(const STREET lhs, const STREET rhs) {
	return lhs.p < rhs.p;
}

int main() {
	freopen("1866.in" , "r", stdin );
	freopen("1866.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	for (int i=0; i<k; i++)
		scanf("%d %d", &street[i].p, &street[i].l);
	sort(street, street+k, StreetSort);
	for (int i=1; i<k; i++) {
		ans = max(ans, street[maxx].l + (street[i].p - street[maxx].p) + street[i].l);
		if (street[i].l > street[maxx].l + (street[i].p - street[maxx].p))
			maxx = i;
	}
	printf("%d\n", ans);

	return 0;
}
