// 1426.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::sort;
using std::min;

const int INF  = 0x7FFF7FFF;
const int MAXN = 100010;
struct NODE { int x, y, z, n; } node[MAXN];
struct EDGE { int u, v, w; } edge[MAXN*3*2];
int cmp1(const NODE lhs, const NODE rhs) { return lhs.x < rhs.x; }
int cmp2(const NODE lhs, const NODE rhs) { return lhs.y < rhs.y; }
int cmp3(const NODE lhs, const NODE rhs) { return lhs.z < rhs.z; }
int (*cmps[])(const NODE, const NODE) = {cmp1, cmp2, cmp3};
int EdgeSort(const EDGE lhs, const EDGE rhs) {
	return lhs.w < rhs.w;
}
int n, edges=0, father[MAXN];

void AddEdge(const int u, const int v, const int w) {
	edge[edges].u = u;
	edge[edges].v = v;
	edge[edges].w = w;
	edges ++;
}

void AddEdge(const NODE u, const NODE v) {
	int dis = INF;
	dis = min(dis, abs(u.x - v.x));
	dis = min(dis, abs(u.y - v.y));
	dis = min(dis, abs(u.z - v.z));
	AddEdge(u.n, v.n, dis);
}

int UFSfindA(const int node) {
	return (father[node]==node)? (node):(father[node]=UFSfindA(father[node]));
}

void UFSmerge(const int lhs, const int rhs) {
	father[UFSfindA(lhs)] = UFSfindA(rhs);
}

long long BuildTree() {
	long long ret=0;
	for (int i=0; i<edges; i++) {
		if (UFSfindA(edge[i].u) != UFSfindA(edge[i].v)) {
			ret += edge[i].w;
		//	printf("Merge %d <=> %d  %d\n", edge[i].u, edge[i].v, edge[i].w);
			UFSmerge(edge[i].u, edge[i].v);
		}
	}
	return ret;
}

int main() {
	freopen("1426.in" , "r", stdin );
	freopen("1426.out", "w", stdout);

	for (int i=0; i<MAXN; i++)
		father[i] = i;

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d %d %d", &node[i].x, &node[i].y, &node[i].z);
		node[i].n = i+1;
	}

	for (int i=0; i<3; i++) {
		sort(node, node+n, cmps[i]);
		for (int i=0; i<n-1; i++) {
			AddEdge(node[ i ], node[i+1]);
			AddEdge(node[i+1], node[ i ]);
		}
	}
	sort(edge, edge+edges, EdgeSort);

	printf("%lld\n", BuildTree());

	return 0;
}
