// 1413.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
using std::abs;

const int MAXN = 40010;
const int MAXM = 40010;
const int MAXK = 10010;
struct FATHER { int f, x, y;    } f[MAXN];
struct QUES   { int u, v, t, n; } q[MAXK];
struct EDGE   { int u, v, x, y; } edge[MAXM];
struct RETER  { int x, y;       };
int k, n, m, ans[MAXN];
char st[5];

int QuestionSort(const QUES lhs, const QUES rhs) {
	return lhs.t < rhs.t;
}

int findA(const int node) {
	if (f[node].f==node) return node;
	int father   = f[node].f;
	int ancestor = findA(father);
	if (father != ancestor) {
		f[node].x += f[father].x;
		f[node].y += f[father].y;
		f[node].f = ancestor;
	}
	return ancestor;
}

RETER GetXY(const int node) {
	RETER ret;
	findA(node);
	ret.x = f[node].x;
	ret.y = f[node].y;
	return ret;
}

void merge(const EDGE edge) {
	if (findA(edge.u) == findA(edge.v)) return;
	int u = edge.u;
	int a = findA(u);
	int x = edge.x, y = edge.y;
	if (u != a) {
		RETER tmp = GetXY(u);
		x -= tmp.x;
		y -= tmp.y;
	}
	f[a].f = edge.v;
	f[a].x += x;
	f[a].y += y;
}

int GetDis(const int u, const int v) {
	if (findA(u) != findA(v)) return -1;
	RETER s = GetXY(u), t = GetXY(v);
	return abs(s.x - t.x) + abs(s.y - t.y);
}

int main() {
	freopen("1413.in" , "r", stdin );
	freopen("1413.out", "w", stdout);
	for (int i=0; i<MAXN; i++)
		f[i].f = i;
	
	scanf("%d %d", &n, &m);
	for (int i=0, u, v, w, x, y; i<m; i++) {
		scanf("%d %d %d %s", &edge[i].u, &edge[i].v, &w, st);
		edge[i].x = edge[i].y = 0;
		switch (st[0]) {
			case 'N': edge[i].y =  w; break;
			case 'E': edge[i].x =  w; break;
			case 'W': edge[i].x = -w; break;
			case 'S': edge[i].y = -w; break;
		}
	}
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		scanf("%d %d %d", &q[i].u, &q[i].v, &q[i].t);
		q[i].n = i;
	}
	sort(q, q+k, QuestionSort);

	for (int i=0, nowE=0; i<k; i++) {
		for (int j=nowE; j<q[i].t; j++)
			merge(edge[j]);
		nowE = q[i].t;
		ans[q[i].n] = GetDis(q[i].u, q[i].v);
	}
	
	for (int i=0; i<k; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
