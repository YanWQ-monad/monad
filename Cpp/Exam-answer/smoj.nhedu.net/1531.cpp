#include <cstdio>

#define clean(arr, con, len) for (int i=1; i<=len; i++) arr[i] = con;
const int MAXN = 50010;
int n, k, ans=0, father[MAXN*3];

int getAncestor(const int node) {
	return (father[node]==node)? (node):(getAncestor(father[node]));
}

void marge(const int x, const int y) {
	father[getAncestor(x)] = getAncestor(y);
}

int main() {
	freopen("1531.in" , "r", stdin );
	freopen("1531.out", "w", stdout);
		
	scanf("%d %d", &n, &k);
	clean(father, i, 3*n);
	for (int i=0, d, x, y; i<k; i++) {
		scanf("%d %d %d", &d, &x, &y);
		if (x>n || y>n) { ans++; continue; }
		if (d == 1) {
			if (getAncestor(x + n) == getAncestor(y)
			 || getAncestor(x+2*n) == getAncestor(y)) {
			 	ans ++;
			 	continue;
			 }
			marge(x    , y    );
			marge(x + n, y + n);
			marge(x+2*n, y+2*n);
		}
		else {
			if (getAncestor(  x  ) == getAncestor(y)
			 || getAncestor(x+2*n) == getAncestor(y)) {
			 	ans ++;
			 	continue;
			 }
			marge(x + n, y    );
			marge(x    , y+2*n);
			marge(y + n, x+2*n); 
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
