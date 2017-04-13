// 1746.cpp
#include <cstdio>

const int MAXN = 30;
char map[MAXN][MAXN];
int n;

void SetMap(const int pos, const char value) {
	for (int i=pos; i<n-pos; i++)
		map[i][pos] = map[i][n-pos-1] = map[n-pos-1][i] = map[pos][i] = value;
}

int main() {
	freopen("1746.in" , "r", stdin );
	freopen("1746.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=n>>1; i>=0; i--)
		SetMap(i, 'A'+i);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			putchar(map[i][j]);
		puts("");
	}
	
	return 0;
}
