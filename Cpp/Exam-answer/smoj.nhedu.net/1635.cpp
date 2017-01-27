// 1635.cpp
#include <algorithm>
#include <cstdio>
using std::max;

enum PSH {
	P=1, S, H, unknown
};

bool win(const char me, const char other) {
	switch(me) {
		case P : return other == H;
		case S : return other == P;
		case H : return other == S;
		default: return false;
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
const int MAXK = 25;
char st[5];
int n, k, h[MAXN], f[MAXN][MAXK][5], ans=0;

int main() {
	freopen("Temp.in" , "r", stdin );
	freopen("Temp.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; i++) {
		scanf("%s", st);
		h[i] = getNum(st[0]);
	}

	for (int i=1; i<=n; i++)
		for (int j=0; j<=k; j++)
			for (int hand=P; hand<=H; hand++) {
				f[i][j][hand] = f[i-1][j][hand] + win(hand, h[i]);
				if (j >= 1)
					for (int old=P; old<=H; old++)
						f[i][j][hand] = max(f[i][j][hand], f[i-1][j-1][old] + win(hand, h[i]));
			}

	for (int i=0; i<=k; i++)
		for (int j=P; j<=H; j++)
			ans = max(ans, f[n][i][j]);

	printf("%d\n", ans);

	return 0;
}
