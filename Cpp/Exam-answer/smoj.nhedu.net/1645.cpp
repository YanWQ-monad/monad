// 1645.cpp
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 200010;
const int MAXM = 200010;

struct PAIR { int s, t; } pair[MAXM];
struct EDGE { int n, t; } edge[MAXM*2];
int n, m, a[MAXN], father[MAXN], tot=1, head[MAXN], cnt[MAXN];
bool can[MAXN], live[MAXN];

void AddEdge(const int from, const int to) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	head[from] = CurEdge;
	CurEdge ++;
}

int findA(const int node) {
	return (father[node] == node)? (node) : (father[node] = findA(father[node]));
}

void merge(const int lhs, const int rhs) {
	int l = findA(lhs),
	    r = findA(rhs);
	if (l != r) {
		father[r] = l;
		cnt[l] += cnt[r];
		tot ++;
	}
}

int main() {
	freopen("1645.in" , "r", stdin );
	freopen("1645.out", "w", stdout);

	for (int i=0; i<MAXN; i++) {
		father[i] = i;
		head[i] = -1;
		cnt[i] = 1;
	}

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &pair[i].s, &pair[i].t);
		AddEdge(pair[i].s, pair[i].t);
		AddEdge(pair[i].t, pair[i].s);
	}
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for (int i=n-1, fn; i>=0; i--) {
		fn = a[i];
		live[fn] = true;
		for (int j=head[fn]; j!=-1; j=edge[j].t)
			if (live[edge[j].n])
				merge(fn, edge[j].n);
		can[i] = cnt[findA(fn)] >= n-i;
		// can[i] = tot >= n-i;
	}

	for (int i=0; i<n; i++)
		puts(can[i]? "YES":"NO");

	return 0;
}
