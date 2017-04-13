// 1726.cpp
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

const int MAXN = 12;
int n, table[MAXN][MAXN], anss=0;
char buf[MAXN];
bool color[12], ans[12];
struct QUERY { int l, r, u, b; };

QUERY GetQuery(const int color) {
	QUERY ret;
	ret.l = ret.b = MAXN;
	ret.r = ret.u = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (table[i][j] == color) {
				ret.l = min(ret.l, i);
				ret.b = min(ret.b, j);
				ret.r = max(ret.r, i);
				ret.u = max(ret.u, j);
			}
	return ret;
}

void Clean(const int color, const QUERY que) {
	for (int i=que.l; i<=que.r; i++)
		for (int j=que.b; j<=que.u; j++)
			if (table[i][j] != color)
				ans[table[i][j]] = false;
}

int main() {
	freopen("1726.in" , "r", stdin );
	freopen("1726.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%s", buf);
		for (int j=0; j<n; j++) {
			table[i][j] = buf[j] - '0';
			color[table[i][j]] = true;
			ans[table[i][j]] = true;
		}
	}

	for (int i=1; i<10; i++) {
		if (!color[i]) continue;
		QUERY que = GetQuery(i);
		Clean(i, que);
	}

	for (int i=1; i<10; i++)
		if (ans[i])
			anss ++;
	printf("%d\n", anss);

	return 0;
}
