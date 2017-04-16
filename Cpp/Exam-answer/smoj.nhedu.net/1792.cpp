// 1792.cpp
#include <cstdio>

const int MAXN = 17;
bool win[MAXN][MAXN];
char tmp[MAXN+3];
int effe[MAXN] = { 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 };
int n, list[MAXN][1<<MAXN];
long long f[MAXN][1<<MAXN];

int count(const int value) {
	int ret = 0;
	for (int i=0; i<n; i++)
		ret += !!(value & (1 << i));
	return ret;
}

int main() {
	freopen("1792.in" , "r", stdin );
	freopen("1792.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%s", tmp);
		for (int j=0; j<n; j++)
			win[i][j] = (tmp[j] == 'Y');
	}

	for (int i=0; i<n; i++)
		f[i][1<<i] = 1;
	for (int i=0, cnt; i<(1<<n); i++)
		if (effe[cnt=count(i)])
			list[cnt][++list[cnt][0]] = i;
	for (int i=2; i<=n; i++) {
		if (!effe[i]) continue;
		for (int j=1, set; j<=list[i][0]; j++) {
			set = list[i][j];
			for (int k=1, last; k<=list[i>>1][0]; k++) {
				last = list[i>>1][k];
				if ((last & set) != last) continue;
				for (int a=0; a<n; a++) {
					if (!(set&(1<<a))) continue;
					for (int b=0; b<n; b++) {
						if (!(a^b) || !(last&(1<<b)) || !win[a][b]) continue;
						f[a][set] += f[b][last] * f[a][set-last];
					}
				}
			}
		}
	}

	for (int i=0; i<n; i++)
		printf("%lld\n", f[i][(1<<n)-1] * (1<<(n-1)));

	return 0;
}
