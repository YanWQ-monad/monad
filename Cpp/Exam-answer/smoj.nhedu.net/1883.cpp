// 1883.cpp
#include <cstdlib>
#include <cstdio>

int r, n, par, lx, ly, flag;

int main() {
	freopen("1883.in" , "r", stdin );
	freopen("1883.out", "w", stdout);

	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &n, &par);
		flag = 0;
		for (int i=0, x, y; i<n; i++) {
			scanf("%d %d", &x, &y);
			flag |= (1 << ((abs(x) + abs(y)) & 1));
		}
		puts((flag & (1 << par))? "CAN":"CANNOT");
	}

	return 0;
}
