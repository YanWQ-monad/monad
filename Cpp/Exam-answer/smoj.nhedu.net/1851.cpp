// 1851.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;
using std::min;

const long long MAXN = 55;
struct mRect { long long left, bottom, right, up; } rect[MAXN];
struct NODE { long long x, y; } node[MAXN];
long long r, n, w, h, ans=0, x[MAXN*2], y[MAXN*2];
long long need;

bool is_inc(const mRect father, const mRect sub) {
	return father.left <= sub.left && father.bottom <= sub.bottom && father.right >= sub.right && father.up >= sub.up;
}

long long GetArea() {
	long long ans = 0;
	for (long long i=0; i<n; i++) {
		x[i*2] = rect[i].left  ;  x[i*2+1] = rect[i].right;
		y[i*2] = rect[i].bottom;  y[i*2+1] = rect[i].up   ;
	}
	sort(x, x+2*n);
	sort(y, y+2*n);

	for (long long i=0, left, bottom, right, up; i<2*n-1; i++)
		for (long long j=0; j<2*n-1; j++) {
			bool isin = false;
			left   = x[i];  right = x[i+1];
			bottom = y[j];  up    = y[j+1];
			if (up == bottom || left == right) continue;
			for (long long k=0; k<n && !isin; k++)
				isin = is_inc(rect[k], (mRect){left, bottom, right, up});
			if (isin) {
				ans += (long long)(right - left) * (up - bottom);
			}
		}
	return ans;
}

mRect AND(const mRect lhs, const mRect rhs) {
	return (mRect){
		max(lhs.left  , rhs.left  ),
		max(lhs.bottom, rhs.bottom),
		min(lhs.right , rhs.right ),
		min(lhs.up    , rhs.up    )
	};
}

bool check(const long long k) {
	for (long long i=0; i<n; i++) {
		rect[i] = AND((mRect){1, 1, w, h}, mRect{node[i].x-k, node[i].y-k, node[i].x+k, node[i].y+k});
		rect[i].right ++;  rect[i].up ++;
	}
	return need <= (long long)w * h - GetArea();
}

long long find() {
	long long l=0, r=2147483647, mid;
	while (l + 1 < r) {
		mid = (int)(((long long)l + r) / 2);
		if (check(mid)) l = mid;
		else            r = mid;
	}
	return l;
}

int main() {
	freopen("1851.in" , "r", stdin );
	freopen("1851.out", "w", stdout);
	
	scanf("%lld", &r);
	while (r--) {
		scanf("%lld %lld %lld %lld", &w, &h, &need, &n);
		for (long long i=0; i<n; i++)
			scanf("%lld %lld", &node[i].x, &node[i].y);
		printf("%lld\n", find());
	}

	return 0;
}
