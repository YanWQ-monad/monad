// 1853.cpp
#include <algorithm>
#include <cstdio>
#include <cmath>
using std::max;
using std::min;

int n, x, y, z, a, b;

bool check(const int d, const int m) {
	const int need_money = m * z + a;
	int cur_n=n, cur_m=0, cur_r=0, cur_d=0;
	for (; cur_n<n+m; cur_n++) { // 先招满m名职员
		while (cur_m < z * (cur_n - n + 1)) { // 不够钱
			int to_m = max(0, min(cur_n, (int)ceil((double)(need_money - cur_m) / x)));
			cur_m += x * to_m;
			cur_r += y * (cur_n - to_m);
			cur_d ++;
		}
		for (int i=0; i<3; i++) { // 三天广告
			int to_m = max(0, min(cur_n, (int)ceil((double)(need_money - cur_m) / x)));
			cur_m += x * to_m;
			cur_r += y * (cur_n - to_m);
			cur_d ++;
		}
		if (cur_d > d) return false;
	}
	int rc = (d - cur_d) * cur_n;
	for (int i=0; i<rc; i++) { // 剩下的时间
		if (cur_m < need_money) cur_m += x;
		else                    cur_r += y;
	}
	return (cur_m >= need_money) && (cur_r >= b);
}

int find() {
	int l=0, r=100, mid, can, i;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		for (i=can=0; !can && i<=r/3; i++)
			can = check(mid, i);
		if (can) r = mid;
		else     l = mid;
	}
	return r;
}

int main() {
	freopen("1853.in" , "r", stdin );
	freopen("1853.out", "w", stdout);

	scanf("%d %d %d %d %d %d", &n, &x, &y, &z, &a, &b);
	printf("%d\n", find());

	return 0;
}
