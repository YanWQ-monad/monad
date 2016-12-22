#include <cstdio>

#define clean(arr, con, len) for (int i=0; i<len ; i++) arr[i] = con;
#define iftdo(con, tdo, len) for (int i=1; i<=len; i++) if(con) {tdo;}
const int MAXN = 110;
const int MAXM = 4510;
typedef enum {DO, DOING, DID} status;
bool edge[MAXN][MAXN];
int n, m, ans=0;

int main() {
	freopen("1530.in" , "r", stdin );
	freopen("1530.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i=0, a, b; i<m; i++) {
		scanf("%d %d", &a, &b);
		edge[a][b] = true;
	}
	
	for (bool flat=true; flat; ) {
		flat = false;
		for (int a=1; a<=n; a++)
			for (int b=1; b<=n; b++)
				for (int c=1; c<=n; c++)
					if (a!=b && b!=c && a!=c &&
					    edge[a][b] && edge[b][c] && !edge[a][c]) {
						flat = edge[a][c] = true;
					}
	}
	
	for (int i=1, edges; i<=n; i++) {
		edges=0;
		for (int j=1; j<=n; j++) {
			if      (i == j)     ;
			else if (edge[i][j]) edges++;
			else if (edge[j][i]) edges++;
		}
		if (edges == n-1) {
			ans ++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
