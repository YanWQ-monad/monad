// 1633.cpp
#include <algorithm>
#include <cstdio>
using std::max;

enum PSH {
	P=1, S, H, unknown
};

int win(const char _psh) {
	switch(_psh) {
		case P : return H;
		case S : return P;
		case H : return S;
		default: return unknown;
	}
}

int getNum(const char _psh) {
	switch(_psh) {
		case 'P': return P;
		case 'S': return S;
		case 'H': return H;
		default : return unknown;
	}
}

const int MAXN = 100010;
int n, sum[MAXN][5], ans=0;
char psh[MAXN], st[5];

int getSum(const int begin, const int end, const int _psh) {
	return sum[end][_psh] - sum[begin-1][_psh];
}

int main() {
	freopen("Temp.in" , "r", stdin );
	freopen("Temp.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%s", st);
		psh[i] = getNum(st[0]);
		sum[i][P] = sum[i-1][P] + (psh[i] == P);
		sum[i][S] = sum[i-1][S] + (psh[i] == S);
		sum[i][H] = sum[i-1][H] + (psh[i] == H);
	}

	for (int i=1, wins; i<n; i++) {
		for (int j=P; j<=H; j++)
			for (int k=P; k<=H; k++) {
				wins = getSum(1, i, win(j)) + getSum(i+1, n, win(k));
				ans = max(ans, wins);
			}
	}

	printf("%d\n", ans);

	return 0;
}
