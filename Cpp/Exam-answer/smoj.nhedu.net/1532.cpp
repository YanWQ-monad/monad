#include <cstdio>

#define clean(arr, con, len) for (int i=0; i<len ; i++) arr[i] = con;
const int MAXN = 100010;
const int MAXM = 100010;
int n, m, p, father[MAXN];

int GetAncestor(int node) {
	return (father[node] == node)? (node):(father[node] = GetAncestor(father[node]));
}

void marge(const int from, const int to) {
	father[GetAncestor(from)] = GetAncestor(to);
}

int main() {
	freopen("1532.in" , "r", stdin );
	freopen("1532.out", "w", stdout);
	
	clean(father, i, MAXN);
	
	scanf("%d %d", &n, &m);
	for (int i=0, a, b; i<m; i++) {
		scanf("%d %d", &a, &b);
		marge(a, b);
	}
	
	scanf("%d", &p);
	for (int i=0, a, b; i<p; i++) {
		scanf("%d %d", &a, &b);
		puts((GetAncestor(a) == GetAncestor(b))? "Yes":"No");
	}
	
	return 0;
}
