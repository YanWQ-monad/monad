#include <algorithm>
#include <cstdio>
using std::max;

#define clean(arr, con, len) for(int i=0; i<len; i++) arr[i]=con;
const int MAXN = 2010;
const int MAXM = 10010;
typedef enum {DO, DOING, DID} status;
struct EDGE {int n, t, l;} edge[MAXM*2];
int n, m, head[MAXN];

void AddEdge(const int from, const int to, const int length) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	edge[CurEdge].l = length;
	head[from] = CurEdge;
	CurEdge ++;
}

char s[MAXN];
int nodes, q[MAXN];
void bfs(const int begin, const int k) {
	int h=0, t=0;
	s[ q[t++] = begin ] = DOING;
	while (h < t) {
		nodes ++;
		for (int i=head[q[h]]; i!=-1; i=edge[i].t)
			if (s[edge[i].n] == DO && edge[i].l <= k) {
				s[ q[t++] = edge[i].n ] = DOING;
			}
		s[q[h++]] = DID;
	}
}

int find() {
	int l=-1, r=0x3FFFFFFF, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		nodes = 0;
		clean(s, DO, n+1);
		bfs(1, mid);
		if (nodes >= n) r = mid;
		else            l = mid;
	}
	return r;
}

int main() {
	freopen("1527.in", "r", stdin);
	freopen("1527.out", "w", stdout);
		
	scanf("%d %d", &n, &m);
	clean(head, -1, n+1);
	
	for (int i=0, a, b, c; i<m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		AddEdge(a, b, c);
		AddEdge(b, a, c);
	}
	
	printf("%d\n", find());
	
	return 0;
}
