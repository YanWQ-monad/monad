// 1590.cpp
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 310;
struct EDGE {int from, to, pos;} edge[MAXN*MAXN];
int n, conn[MAXN][MAXN], father[MAXN], totEdge=0, ans=0;
int findAncestor(const int node) {
	return (father[node]==node)? (node):(father[node]=findAncestor(father[node]));
}

void merge(const int x, const int y) {
	father[findAncestor(x)] = findAncestor(y);
}

int EdgeSort(const EDGE lhs, const EDGE rhs) {
	return lhs.pos < rhs.pos;
}

void build() {
	for (int i=0, edges=0; i<totEdge && edges<n; i++) {
		if (findAncestor(edge[i].from) != findAncestor(edge[i].to)) {
			ans += edge[i].pos;
			merge(edge[i].from, edge[i].to);
			edges++;
		}
	}
}

int main() {
	freopen("1590.in" , "r", stdin );
	freopen("1590.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++)
		father[i] = i;
	
	scanf("%d", &n);
	for (int i=0, p; i<=n; i++)
		for (int j=0; j<n; j++) {
			scanf("%d", &p);
			if (i <= j) {
				edge[totEdge].from = i;
				edge[totEdge].to   = j+1;
				edge[totEdge].pos  = p;
				totEdge++;
			}
		}
	
	sort(edge, edge+totEdge, EdgeSort);
	build();
	
	printf("%d\n", ans);
	
	return 0;
}
