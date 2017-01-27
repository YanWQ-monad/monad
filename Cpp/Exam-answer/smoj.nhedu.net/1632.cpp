// 1632.cpp
#include <algorithm>
#include <cstdio>

template<typename T, const int MAX_LEN>
class mWinnerTree {
 protected:
	int len, k;
	bool isNone[MAX_LEN];
	T mi[MAX_LEN], ma[MAX_LEN];
	int ipos[MAX_LEN], apos[MAX_LEN];
 public:
	void clear() {
		for (int i=0; i<MAX_LEN; i++)
			isNone[i] = true;
		for (int i=k; i<2*k; i++)
			ipos[i] = apos[i] = i - k + 1;
	}
	mWinnerTree(const int size = 0) : len(size), k(1) {
		while (k < size) k <<= 1;
		clear();
	}
	void setLen(const int size) {
		k = 1;
		len = size;
		while (k < size) k <<= 1;
		clear();
	}
	T edit(const int _pos, const T con) {
		int pos = _pos + k - 1, temp;
		ma[pos] = mi[pos] = con;
		isNone[pos] = false;
		while (pos >>= 1) {
			if (isNone[pos*2] && isNone[pos*2+1])
			isNone[pos] = true;
			else {
				isNone[pos] = false;
				if (isNone[pos*2] || isNone[pos*2+1]) {
					if (isNone[pos*2]) temp = pos*2+1;
					else               temp = pos * 2;
					mi[pos] = mi[temp];
					ma[pos] = ma[temp];
					ipos[pos] = ipos[temp];
					apos[pos] = apos[temp];
				}
				else {
					mi[pos] = std::min(mi[pos*2], mi[pos*2+1]);
					ma[pos] = std::max(ma[pos*2], ma[pos*2+1]);
					apos[pos] = apos[(ma[pos*2] < ma[pos*2+1])? (pos*2+1):(pos*2)];
					ipos[pos] = ipos[(mi[pos*2] < mi[pos*2+1])? (pos*2):(pos*2+1)];
				}
			}
		}
		return con;
	}
	T operator[](const int pos) {
		return ma[pos + k - 1];
	}
	bool exist(const int pos) const {
		return !isNone[pos + k - 1];
	}
	T min() const {
		return mi[1];
	}
	int min_pos() const {
		return ipos[1];
	}
	T max() const {
		return ma[1];
	}
	int max_pos() const {
		return apos[1];
	}
};

const int MAXN = 10010;
mWinnerTree<int, MAXN*4> wt;
int n, maxt, t[MAXN];

int count(const int k) {
	int cur = 0;
	wt.clear();
	for (int i=1; i<=k; i++)
		wt.edit(i, t[i]);
	for (int i=k+1, pos, ti; i<=n; i++) {
		pos = wt.min_pos();
		ti = wt.min();
		cur = ti;
		wt.edit(pos, t[i] + cur);
	}
	return wt.max();
}

int find() {
	int l = 0, r = n + 1, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (count(mid) <= maxt) r = mid;
		else                    l = mid;
	}
	return r;
}

int main() {
	freopen("1632.in" , "r", stdin );
	freopen("1632.out", "w", stdout);

	scanf("%d %d", &n, &maxt);
	wt.setLen(n+1);
	for (int i=1; i<=n; i++)
		scanf("%d", &t[i]);

	printf("%d\n", find());

	return 0;
}
