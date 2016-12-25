// 1592.cpp
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 110;
struct EDGE {int from, to, len;} edge[MAXN*MAXN];
int n, father[MAXN], f[MAXN][MAXN], TotEdge=0, ans=0;
int findAncestor(const int node) {
	return (father[node]==node)? (node):(father[node]=findAncestor(father[node]));
}

void merge(const int x, const int y) {
	father[findAncestor(x)] = findAncestor(y);
}

int EdgeSort(const EDGE lhs, const EDGE rhs) {
	return lhs.len < rhs.len;
}

void read() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &f[i][j]);
}

void toEdge() {
	TotEdge=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++) {
			edge[TotEdge].from = i;
			edge[TotEdge].to = j;
			edge[TotEdge].len = f[i][j];
			TotEdge++;
		}
}

void buildTree() {
	int edges=0;
	for (int i=0; i<TotEdge && edges<n-1; i++) {
		if (findAncestor(edge[i].from) != findAncestor(edge[i].to)) {
			ans += f[edge[i].from][edge[i].to];
			merge(edge[i].from, edge[i].to);
			edges++;
		}
	}
}

int main() {
	freopen("1592.in" , "r", stdin );
	freopen("1592.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++)
		father[i] = i;
	
	read();
	toEdge();
	sort(edge, edge+TotEdge, EdgeSort);
	buildTree();
	printf("%d\n", ans);
	
	return 0;
}
