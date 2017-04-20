// 1809.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int INF  = 0x3FFFFFFF;
const int MAXC = 45;
const int MAXN = 420;
int n, m, value[MAXN], card[5], f[MAXC][MAXC][MAXC][MAXC];

int main() {
	freopen("1809.in" , "r", stdin );
	freopen("1809.out", "w", stdout);
	for (int i=0; i<MAXC; i++)
		for (int j=0; j<MAXC; j++)
			for (int k=0; k<MAXC; k++)
				for (int l=0; l<MAXC; l++)
					f[i][j][k][l] = -INF;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++)
		scanf("%d", &value[i]);
	for (int j=0, d; j<m; j++) {
		scanf("%d", &d);
		card[d] ++;
	}

	f[0][0][0][0] = value[0];
	for (int i=0; i<=card[1]; i++)
		for (int j=0; j<=card[2]; j++)
			for (int k=0; k<=card[3]; k++)
				for (int l=0; l<=card[4]; l++) {
					if (i) f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l] + value[1*i+2*j+3*k+4*l]);
					if (j) f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l] + value[1*i+2*j+3*k+4*l]);
					if (k) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k-1][l] + value[1*i+2*j+3*k+4*l]);
					if (l) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l-1] + value[1*i+2*j+3*k+4*l]);
				}

	printf("%d\n", f[card[1]][card[2]][card[3]][card[4]]);


	return 0;
}
