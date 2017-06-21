// 1871.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int MAXN = 100010;
bool x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
int n, m, ans=0;
typedef enum {
	LEFT_UP=0,
	LEFT_DOWN,
	RIGHT_DOWN,
	RIGHT_UP
} ANGLE;

void next(int &x, int &y, int &angle) {
	int dis;
	switch (angle) {
		case LEFT_UP:
			dis = min(x, y);
			x = x - dis;
			y = y - dis;
			angle = (x==0)? RIGHT_UP:LEFT_DOWN;
			break;
		case LEFT_DOWN:
			dis = min(x, m-y);
			x = x - dis;
			y = y + dis;
			angle = (x==0)? RIGHT_DOWN:LEFT_UP;
			break;
		case RIGHT_DOWN:
			dis = min(n-x, m-y);
			x = x + dis;
			y = y + dis;
			angle = (x==n)? LEFT_DOWN:RIGHT_UP;
			break;
		case RIGHT_UP:
			dis = min(n-x, y);
			x = x + dis;
			y = y - dis;
			angle = (x==n)? LEFT_UP:RIGHT_DOWN;
			break;
	}
}

void calc(int x, int y, int angle) {
	while (true) {
		next(x, y, angle);
		if (x == 0) { if (x1[y]) break; x1[y] = true; }
		if (y == 0) { if (y1[x]) break; y1[x] = true; }
		if (x == n) { if (x2[y]) break; x2[y] = true; }
		if (y == m) { if (y2[x]) break; y2[x] = true; }
		if ((x == 0 || x == n) && (y == 0 || y == m)) break;
	}
}

int main() {
	freopen("1871.in" , "r", stdin );
	freopen("1871.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	calc(0, 0, RIGHT_DOWN);
	calc(n, 0, LEFT_DOWN);
	calc(0, m, RIGHT_UP);
	calc(n, m, LEFT_UP);

	for (int i=1; i<m; i++)
		ans += x1[i] + x2[i];
	for (int i=1; i<n; i++)
		ans += y1[i] + y2[i];
	printf("%d\n", ans*2);

	return 0;
}
