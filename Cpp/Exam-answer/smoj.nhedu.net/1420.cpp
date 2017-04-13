// 1420.cpp
#include <cstdio>

const int INF  = 0x7FFF7FFF;
const int MAXN = 310;
const int MAXM = 14010;
struct LIGHT { bool c; int r, b, p; } light[MAXN];
struct EDGE  { int next, to, w;     } edge [MAXM*2];
int s, t, n, m, head[MAXN], queue[MAXN], hq=0, tq=0, tim[MAXN];
bool v[MAXN];
char st[10];

void AddEdge(const int u, const int v, const int w) {
	static int curEdge = 0;
	edge[curEdge].next = head[u];
	edge[curEdge].to   = v;
	edge[curEdge].w    = w;
	head[u] = curEdge ++;
}

void Push(const int node) {
	if (v[node]) return;
	queue[(tq ++) % MAXN] = node;
	v[node] = true;
}

int Pop() {
	int ret = queue[(hq ++) % MAXN];
	v[ret] = false;
	return ret;
}

bool GetColor(const int u, const int t) {
	int ret = t;
	if (ret < light[u].r) return light[u].c;
	int range = (ret - light[u].r) % (light[u].b + light[u].p);
	if (light[u].c) return range >= light[u].p;
	else            return range <  light[u].b;
}

int NextByStep(const int u, const int v, const int step, const int end) {
	for (int i=tim[u]; i<end; i+=step)
		if (GetColor(u, i) == GetColor(v, i))
			return i;
	return -1;
}

int GetNextTime(const int u, const int v) {
	int ret = 0x20000, tim;
	bool can = false;
	for (int i=0x20000; i; i>>=1)
		if ((tim = NextByStep(u, v, i, ret)) != -1) {
			ret = tim;
			can = true;
		}
	return can? ret:INF;
}

bool CanRelax(const int u, const int v, const int w) {
	if (GetNextTime(u, v) + w < tim[v]) return true;
	else                                return false;
}

void SPFA(const int begin) {
	tim[s] = 0;
	Push(s);
	while (hq < tq)
		for (int curN = Pop(), i=head[curN]; i!=-1; i=edge[i].next)
			if (CanRelax(curN, edge[i].to, edge[i].w)) {
				tim[edge[i].to] = GetNextTime(curN, edge[i].to) + edge[i].w;
				Push(edge[i].to);
			}
}

int main() {
	freopen("1420.in" , "r", stdin );
	freopen("1420.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++) {
		head[i] = -1;
		tim[i] = INF;
	}
	
	scanf("%d %d %d %d", &s, &t, &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%s %d %d %d", st, &light[i].r, &light[i].b, &light[i].p);
		light[i].c = st[0] == 'B';
	}
	for (int j=0, u, v, w; j<m; j++) {
		scanf("%d %d %d", &u, &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}
	
	SPFA(s);
	printf("%d\n", tim[t]>=INF? 0:tim[t]);
	
	return 0;
}
