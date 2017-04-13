// 1711.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MOD  = 1000000007;
const int MAXN = 55;
int r, n, f[MAXN][MAXN][MAXN][3], color[3], taste[MAXN], ans;
char st[MAXN];

typedef enum {
	A=0, B, C
}colour;

int main() {
	freopen("1711.in" , "r", stdin );
	freopen("1711.out", "w", stdout);

	scanf("%d", &r);
	while (r --) {
		scanf("%d %s", &n, st);
		ans = color[0] = color[1] = color[2] = 0;
		for (int i=0; i<n; i++)
			switch(st[i]) {
				case 'A': color[A] ++; taste[i] = A; break;
				case 'B': color[B] ++; taste[i] = B; break;
				case 'C': color[C] ++; taste[i] = C; break;
			}

		for (int g=A; g<=C; g++) {
			if (!color[g]) continue;
			for (int i=0; i<=color[A]; i++)
				for (int j=0; j<=color[B]; j++)
					for (int k=0; k<=color[C]; k++)
						f[i][j][k][A] = f[i][j][k][B] = f[i][j][k][C] = 0;
			f[g==A][g==B][g==C][g] = 1;
			for (int i=0; i<=color[A]; i++)
				for (int j=0; j<=color[B]; j++)
					for (int k=0; k<=color[C]; k++)
						for (int c=A; c<=C; c++) {
							if (!color[c] || (i + j + k >= n && c == g)) continue;
							for (int d=A; d<=C; d++)
								if (c != d) {
									if (i && c==A) f[i][j][k][c] = (f[i][j][k][c] + f[i-1][j][k][d]) % MOD;
									if (j && c==B) f[i][j][k][c] = (f[i][j][k][c] + f[i][j-1][k][d]) % MOD;
									if (k && c==C) f[i][j][k][c] = (f[i][j][k][c] + f[i][j][k-1][d]) % MOD;
								}
						}
			for (int c=A; c<=C; c++)
				if (c != g)
					ans = (ans + f[color[A]][color[B]][color[C]][c]) % MOD;
		}
		printf("%d\n", ans);
	}

	return 0;
}
