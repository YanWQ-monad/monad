#include <cstdio>

const int MAXK = 1010;
const int MAXN = 50010;
typedef enum {DO, DOING, DID} status;
struct EDGE {int n, t;} edge[MAXN];
int n, k, head[MAXK];
int temp[MAXN][2];

void AddEdge(const int from, const int to) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	head[from] = CurEdge;
	CurEdge ++;
}

struct BFS_T {int f, n;} q[MAXN];
char s[MAXK];
int stack[MAXK];
void print(const int begin) {
	int CurStack = 0;
	for (int i=begin; i!=-1; i=q[i].f)
		stack[CurStack++] = q[i].n;
	printf("%d\n", CurStack);
	for (int i=CurStack-1; i>=0; i--)
		printf("%d\n", stack[i]);
}
void bfs(const int begin) {
	int h=0, t=0;
	q[t].f = -1;
	q[t].n = begin;
	t ++;
	while (h < t) {
		if (q[h].n == k) { print(h); return; }
		s[q[h].n] = DOING;
		for (int i=head[q[h].n]; i!=-1; i=edge[i].t) {
			if (s[edge[i].n] != DO) continue;
			q[t].f = h;
			q[t].n = edge[i].n;
			t ++;
		}
		s[q[h].n] = DID;
		h ++;
	}
	puts("-1");
}

int main() {
	freopen("1526.in", "r", stdin);
	freopen("1526.out", "w", stdout);
	
	for (int i=0; i<MAXK; i++) {
		head[i] = -1;
		s[i] = DO;
	}
	
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++)
		scanf("%d %d", &temp[i][0], &temp[i][1]);

	for (int i=n-1; i>=0; i--)
		AddEdge(temp[i][0], temp[i][1]);
	
	bfs(1);
	
	return 0;
}
