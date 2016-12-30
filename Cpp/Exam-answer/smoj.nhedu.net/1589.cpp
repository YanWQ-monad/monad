// 1589.cpp
#include <algorithm>
#include <cstdio>
#include <cmath>
using std::sort;

const int MAXN = 1010;
struct EDGE {int from, to; double pos;} edge[MAXN*MAXN];
struct NODE {int x, y;} nodes[MAXN];
int n, m, father[MAXN], totEdge=0;
double ans=0.0;
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

double len(const int x1, const int y1, const int x2, const int y2) {
	return sqrt((long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2));
}

int main() {
	freopen("1589.in" , "r", stdin );
	freopen("1589.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++)
		father[i] = i;
	
	scanf("%d %d", &n, &m);
	for (int i=1, x, y; i<=n; i++) {
		scanf("%d %d", &nodes[i].x, &nodes[i].y);
	}
	
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++) {
			if (nodes[i].x == nodes[j].x && nodes[i].y == nodes[j].y) continue;
			edge[totEdge].from = i;
			edge[totEdge].to   = j;
			edge[totEdge].pos  = len(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y);
			totEdge++;
		}
	
	for (int i=0, x, y; i<m; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	
	sort(edge, edge+totEdge, EdgeSort);
	build();
	
	printf("%.2lf\n", ans);
	
	return 0;
}
