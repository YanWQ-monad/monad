// 1811.cpp
#include <cstdio>

const int MAXN = 1010;
const int MAXX = 2005; 

struct NODE { int x, y; } node[MAXN];
int n, ans=0;
bool exist[MAXX*2][MAXX*2];

int main() {
	freopen("1811.in" , "r", stdin );
	freopen("1811.out", "w", stdout);
	
	while (scanf("%d", &n), n>0) {
		ans = 0;
		for (int i=0; i<n; i++) {
			scanf("%d %d", &node[i].x, &node[i].y);
			if (node[i].x > MAXX || node[i].y > MAXX) {
				n --;
				i --;
			}
			node[i].x += MAXX;
			node[i].y += MAXX;
			exist[node[i].x][node[i].y] = true;
		}
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i != j) {
					int h = (node[i].y - node[j].y);
					int w = (node[i].x - node[j].x);
					ans += exist[node[j].x-h][node[j].y+w] && exist[node[i].x-h][node[i].y+w];
					ans += exist[node[j].x+h][node[j].y-w] && exist[node[i].x+h][node[i].y-w];
				}
		for (int i=0; i<n; i++)
			exist[node[i].x][node[i].y] = false;
		printf("%d\n", ans/8);
	}

	return 0;
}
