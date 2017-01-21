// 1629.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::max;
using std::min;

struct EDGE {
	int a, b, f, t ,p, next;
	EDGE() : a(0), b(0), f(0), t(0), p(0), next(0) {}
	EDGE(const int at, const int bt, const int ft, const int tt, const int pt, const int nt)
	     : a(at), b(bt), f(ft), t(tt), p(pt), next(nt)
		{}
	long long GetArriveTime(const long long BeginTime) {
		if      (BeginTime <= f)          return (long long)f + t;
		else if ((BeginTime - f) % p > 0) return BeginTime + (p - (BeginTime - f) % p) + t;
		else                              return BeginTime + t;
	}
};

#define clean(arr, con, len) for (int i=0; i<=len; i++) arr[i] = con;
const long long INF = 0x3FFFFFFFFFFFFFF;
const int MAXN = 600;
const int MAXM = 600;

EDGE edge[MAXM];
int n, m, time, head[MAXN];
long long dis[MAXN];
bool used[MAXN];

void AddEdge(const int a, const int b, const int f, const int t, const int p) {
	static int CurEdge = 0;
	EDGE temp(a, b, f, t, p, head[a]);
	edge[CurEdge] = temp;
	head[a] = CurEdge;
	CurEdge ++;
}

void FindMinest(long long &value, int &pos) {
	value = INF; pos = -1;
	for (int i=1; i<=n; i++)
		if (!used[i] && dis[i] < value) {
			value = dis[i];
			pos = i;
		}
}

void relax(const int node, const int k) {
	long long NewTime;
	for (int i=head[node], to; i!=-1; i=edge[i].next) {
		to = edge[i].b;
		NewTime = edge[i].GetArriveTime(dis[node] + k);
		if (!used[to])
			dis[to] = min(NewTime, dis[to]);
	}
}

int Dijkstra(const int start, const int k) {
	memset(used, 0, sizeof(used));
	clean(dis, INF, n);
	dis[start] = 0;
	for (int i=head[start]; i!=-1; i=edge[i].next)
		dis[edge[i].b] = min(dis[edge[i].b], (long long)edge[i].t + edge[i].f);
	long long value=0;
	for (int trees=1, pos=0; trees<n; trees++) {
		FindMinest(value, pos);
		if (value == INF && pos == -1) break;
		used[pos] = true;
		relax(pos, k);
	}
	return 0;
}

int find() {
	int l = 0, r = 0x7FFFFFFF, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		Dijkstra(1, mid);
		if (dis[n] <= time) l = mid;
		else                r = mid;
	}
	return l;
}

int main() {
	freopen("1629.in" , "r", stdin );
	freopen("1629.out", "w", stdout);
	for (int i=0; i<MAXN; i++) {
		head[i] = -1;
	}

	scanf("%d %d %d", &n, &m, &time);
	for (int i=0, a, b, f, t, p; i<m; i++) {
		scanf("%d %d %d %d %d", &a, &b, &f, &t, &p);
		AddEdge(a, b, f, t, p);
	}

	Dijkstra(1, 1);
	if (dis[n] > time) puts("-1");
	else               printf("%d\n", find());

	return 0;
}
