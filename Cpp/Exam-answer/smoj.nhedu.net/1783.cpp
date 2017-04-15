// 1783.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int INF  = 0xFFFF;
const int MAXN = 10010;
struct EDGE {
	int to;
	EDGE *next;
	EDGE() : to(0), next(NULL) {}
}edge[MAXN*2];
EDGE* head[MAXN];
typedef enum {
	TOWER=0,
	SIGN_FATHER,
	SIGN_SON
}STATUS;
int n, value[MAXN], f[MAXN][3];
bool u[MAXN];

void AddEdge(const int u, const int v) {
	static int curE = 0;
	edge[curE].to = v;
	edge[curE].next = head[u];
	head[u] = &(edge[curE]);
	curE ++;
}

void dfs(const int node, const int father) {
	u[node] = true;
	f[node][TOWER] = 1;
	bool ran = false;
	int minn = INF, pos = 0;
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		dfs(cur->to, node);
	}
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
	//	dfs(cur->to, node);
		f[node][TOWER] += min(f[cur->to][SIGN_FATHER], min(f[cur->to][TOWER], f[cur->to][SIGN_SON]));
		if (minn > (f[cur->to][TOWER] - f[cur->to][SIGN_SON])) {
			minn = f[cur->to][TOWER] - f[cur->to][SIGN_SON];
			pos = cur->to;
		}
		f[node][SIGN_FATHER] += min(f[cur->to][SIGN_SON], f[cur->to][TOWER]);
		ran = true;
	}
	for (EDGE *cur=head[node]; cur!=NULL; cur=cur->next) {
		if (cur->to == father) continue;
		if (cur->to == pos)    f[node][SIGN_SON] += f[cur->to][TOWER];
		else                   f[node][SIGN_SON] += min(f[cur->to][SIGN_SON], f[cur->to][TOWER]);
	}
	if (!ran) f[node][SIGN_SON] = INF;

	
}

int main() {
	freopen("1783.in" , "r", stdin );
	freopen("1783.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0, u, v; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	dfs(1, -1);


	printf("%d\n", min(f[1][TOWER], f[1][SIGN_SON]));

	return 0;
}
