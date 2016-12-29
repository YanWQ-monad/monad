// 1591.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::min;

const int INF  = 0x7FFFFFFF;
const int MAXN = 10010;
const int MAXP = 100010;
struct EDGE {int from, to, pos;} edge[MAXP];
int n, p, cow[MAXN], father[MAXN], totEdge=0, ans=INF;
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
	freopen("1591.in" , "r", stdin );
	freopen("1591.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++)
		father[i] = i;
	
	scanf("%d %d", &n, &p);
	for (int i=0; i<n; i++) {
		scanf("%d", &cow[i+1]);
		ans = min(ans, cow[i+1]);
	}
	for (int i=0, s, e, l; i<p; i++) {
		scanf("%d %d %d", &s, &e, &l);
		edge[totEdge].from = s;
		edge[totEdge].to   = e;
		edge[totEdge].pos  = l * 2 + cow[s] + cow[e];
		totEdge++;
	}
	
	sort(edge, edge+totEdge, EdgeSort);
	build();
	
	printf("%d\n", ans);
	
	return 0;
}
