// 1639.cpp
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 1010;
struct EDGE {int u, v, w;} edge[MAXN*MAXN];
struct NODE {int x, y;}    node[MAXN];
int n, father[MAXN], TotEdge=0, ans=0;

int findAncestor(const int node) {
	return (father[node]==node)? (node):(father[node]=findAncestor(father[node]));
}

void merge(const int x, const int y) {
	father[findAncestor(x)] = findAncestor(y);
}

int EdgeSort(const EDGE lhs, const EDGE rhs) {
	return lhs.w < rhs.w;
}

void buildTree() {
	int edges=0;
	for (int i=0; i<TotEdge && edges<n-1; i++)
		if (findAncestor(edge[i].u) != findAncestor(edge[i].v)) {
			ans = edge[i].w;
			merge(edge[i].u, edge[i].v);
			edges++;
		}
}

int dis(const int x1, const int y1, const int x2, const int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	freopen("1639.in" , "r", stdin );
	freopen("1639.out", "w", stdout);
	for (int i=0; i<MAXN; i++)
		father[i] = i;

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d %d", &node[i].x, &node[i].y);
		for (int j=0; j<i; j++) {
			edge[TotEdge].u = j;
			edge[TotEdge].v = i;
			edge[TotEdge].w = dis(node[i].x, node[i].y, node[j].x, node[j].y);
			TotEdge ++;
		}
	}
	sort(edge, edge+TotEdge, EdgeSort);

	buildTree();

	printf("%d\n", ans);

	return 0;
}
