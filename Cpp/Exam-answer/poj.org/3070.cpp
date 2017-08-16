// 3070.cpp
#include <cstdio>

const int MOD  = 10000;
const int MAXN = 1000000010;

template <int X, int Y>
class mMatrix {
 private:
	int a[X][Y];
	template<int X2, int Y2>
	struct TIMES;
		// Y != X2, can not do multiplication !

	template<int Y2>
	struct TIMES<Y, Y2> {
		mMatrix<X, Y2> static times(const mMatrix<X, Y> &lhs, const mMatrix<Y, Y2> &rhs) {
			mMatrix<X, Y2> ret;
			for (int i=0; i<X; i++)
				for (int j=0; j<Y; j++)
					for (int k=0; k<Y2; k++)
						ret.a[i][j] = (ret.a[i][j] + lhs.a[i][k] * rhs.a[k][j]) % MOD;
			return ret;
		}
	};
 public:
	mMatrix() {
		for (int i=0; i<X; i++)
			for (int j=0; j<Y; j++)
				a[i][j] = 0;
	}
	mMatrix(const int arr[X][Y]) {
		for (int i=0; i<X; i++)
			for (int j=0; j<Y; j++)
				a[i][j] = arr[i][j];
	}
	template<int X2, int Y2>
	mMatrix<X, Y2> operator*(const mMatrix<X2, Y2> &other) const {
		return TIMES<X2, Y2>::times(*this, other);
	}
	int get(const int x, const int y) const {
		return a[x][y];
	}
};

template<int X>
mMatrix<X, X> pow(const mMatrix<X, X> &base, const int times) {
	mMatrix<X, X> ret = base, tmp = base;
	for (int b=times-1; b; b>>=1) {
		if (b & 1)
			ret = ret * tmp;
		tmp = tmp * tmp;
	}
	return ret;
}

int n, base[2][2]={{0, 1}, {1, 1}}, fib[1][2] = {{1, 1}};

int main() {
	while (scanf("%d", &n), n!=-1) {
		if (n == 0) {
			puts("0");
			continue;
		}
		mMatrix<2, 2> mi = pow(mMatrix<2, 2>(base), n);
		printf("%d\n", mi.get(0, 1));
	}

	return 0;
}
