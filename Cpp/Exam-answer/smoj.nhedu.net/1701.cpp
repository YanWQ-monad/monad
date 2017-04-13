// 1701.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using std::sort;
using std::abs;

class fraction {
 private:
	long long mol, den;
	bool inf, nan;
	inline int gcd(const int lhs, const int rhs) const {
		return (lhs % rhs)? (gcd(rhs, lhs % rhs)):(rhs);
	}
	void reduction() {
		if (inf || nan) return;
		int gc = gcd(mol, den);
		mol /= gc;
		den /= gc;
		if (mol > 0 && den < 0) {
			mol = -mol;
			den = -den;
		}
	}
 public:
	fraction(const int num=0) : mol(num), den(1), inf(false), nan(false) {
	}
	fraction operator+(const fraction &other) {
		fraction ret;
		if (inf || other.inf) {
			ret.inf = true;
			return ret;
		}
		ret.den = den * other.den;
		ret.mol = mol * other.den + den * other.mol;
		ret.reduction();
		return ret;
	}
	fraction operator-(const fraction &other) {
		fraction ret;
		if (inf || other.inf) {
			ret.inf = true;
			return ret;
		}
		ret.den = den * other.den;
		ret.mol = mol * other.den - den * other.mol;
		ret.reduction();
		return ret;
	}
	fraction operator*(const fraction &other) {
		fraction ret;
		if (inf || other.inf) {
			ret.inf = true;
			return ret;
		}
		ret.den = den * other.den;
		ret.mol = mol * other.mol;
		ret.reduction();
		return ret;
	}
	fraction operator/(const fraction &other) {
		fraction ret(0);
		if (!inf && other.inf) {
			return ret;
		}
		if (inf || other.inf) {
			ret.inf = true;
			return ret;
		}
		ret.den = den * other.mol;
		ret.mol = mol * other.den;
		if (ret.den == 0) ret.inf = true;
		else			  ret.reduction();
		return ret;
	}
	bool operator< (const fraction &other) const {
		if (other.inf && inf) return false;
		if (other.inf || inf) return other.inf;
		return mol * other.den < den * other.mol;
	}
	operator double() {
		if (inf) return 1.0 / 0.0;
		return (double)mol / den;
	}
	bool operator> (const fraction &other) const { return other < *this; }
	bool operator<=(const fraction &other) const { return !(*this > other); }
	bool operator>=(const fraction &other) const { return !(*this < other); }
	bool operator!=(const fraction &other) const { return *this < other || other < *this; }
	bool operator==(const fraction &other) const { return !(*this != other); }
};

const int MAXN = 1510;
struct NODE { int x, y; } node[MAXN];
struct EDGE { int to; fraction slope; } edge[MAXN][MAXN];
int n;
long long ans=0;

int EdgeSort(const EDGE lhs, const EDGE rhs) {
	return lhs.slope < rhs.slope;
}

int findSlopeL(const int point, const fraction value) {
	int l = -1, r = n-1, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (edge[point][mid].slope >= value) r = mid;
		else								 l = mid;
	}
	return r;
}

int findSlopeR(const int point, const fraction value) {
	int l = -1, r = n-1, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (edge[point][mid].slope <= value) l = mid;
		else								 r = mid;
	}
	return r;
}

int main() {
	freopen("1701.in" , "r", stdin );
	freopen("1701.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d %d", &node[i].x, &node[i].y);

	for (int i=0, cur; i<n; i++) {
		cur = 0;
		for (int j=0; j<n; j++) {
			if (i == j) continue;
			edge[i][cur].slope = (fraction)(node[i].y - node[j].y) / (fraction)(node[i].x - node[j].x);
			edge[i][cur].to = j;
			cur ++;
		}
		sort(edge[i], edge[i]+cur, EdgeSort);
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if (i == j) continue;
			fraction abS = (fraction)(node[i].y - node[j].y) / (fraction)(node[i].x - node[j].x);
			fraction acS = (fraction)-1.0 / abS;
			ans += findSlopeR(i, acS) - findSlopeL(i, acS);
			ans += findSlopeR(j, acS) - findSlopeL(j, acS);
		}

	printf("%lld\n", ans / 4);

	return 0;
}
