// 1865.cpp
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 12;
int n, x[MAXN*2], y[MAXN*2], ans=0;
class mRect {
	int x1, y1, x2, y2;
 public:
	mRect(int x1t=0, int y1t=0, int x2t=0, int y2t=0)
	    : x1(x1t), y1(y1t), x2(x2t), y2(y2t) {
		if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
		if (y1 < y2) y1 ^= y2 ^= y1 ^= y2;
	}
	bool is_inc(const mRect thr) {
		return x1 <= thr.x1 && y1 >= thr.y1 && x2 >= thr.x2 && y2 <= thr.y2;
	}
};
mRect rs[MAXN];

int main() {
	freopen("1865.in" , "r", stdin );
	freopen("1865.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0, x1, y1, x2, y2; i<n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		rs[i] = mRect(x1, y1, x2, y2);
		x[i*2] = x1; x[i*2+1] = x2;
		y[i*2] = y1; y[i*2+1] = y2;
	}
	sort(x, x+2*n);
	sort(y, y+2*n);

	for (int i=0, x1, y1, x2, y2; i<2*n-1; i++)
		for (int j=0; j<2*n-1; j++) {
			bool isin = false;
			x1 = x[i]; x2 = x[i+1];
			y1 = y[j]; y2 = y[j+1];
			for (int k=0; k<n && !isin; k++)
				isin = isin || rs[k].is_inc(mRect(x1, y1, x2, y2));
			if (isin)
				ans += (x2 - x1) * (y2 - y1);
		}

	printf("%d\n", ans);

	return 0;
}
