// 1755.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::min;

const int INF  = 0x6FFFFFFF;
const int MAXL = 50;
const int MAXN = 100010;
char st[MAXL];
int n, f[MAXL][MAXN], l;

int GetNum(const char *begin, const char *end) {
	int ret=0;
	for (const char *c=begin; c != end; c++) {
		ret = ret * 10 + (*c - '0');
		if (ret < 0 || ret > 1000000) return MAXN;
	}
	ret = ret * 10 + (*end - '0');
	return ret;
}

int main() {
	freopen("1755.in" , "r", stdin );
	freopen("1755.out", "w", stdout);
	
	scanf("%s %d", st+1, &n);
	l = strlen(st+1);
	for (int i=0; i<MAXL; i++)
		for (int j=0; j<MAXN; j++)
			f[i][j] = INF;
	f[0][0] = 0;
	for (int i=1, cur; i<=l; i++)
		for (int j=i; j>=1; j--) {
			cur = GetNum(st+j, st+i);
			if (cur >= MAXN) break;
			for (int k=0; k<=n-cur && k>=0; k++)
				f[i][k+cur] = min(f[i][k+cur], f[j-1][k] + 1);
		}
	
	if (f[l][n] >= INF) puts("-1");
	else                printf("%d\n", f[l][n] - 1);

	return 0;
}
