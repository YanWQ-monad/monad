// 1832.cpp
#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;
using std::min;

const int INF  = 0xFFFFFFF;
const int MAXN = 100010;
vector<int> edge[MAXN];
int n, m[MAXN], s, t, f[MAXN][2], ans;
bool u[MAXN], instack[MAXN], visit[MAXN];

void init() {
	for (int i=0; i<MAXN; i++) {
		visit[i] = false;
		f[i][0] = f[i][1] = INF;
	}
}

void dfs(const int cur, const int father) {
	visit[cur] = true;
	f[cur][0] = 0;
	f[cur][1] = 1;
	for (int i=0; i<(signed)edge[cur].size(); i++) {
		if (edge[cur][i] == father) continue;
		if (cur == s && edge[cur][i] == t) continue;
		if (cur == t && edge[cur][i] == s) continue;
		if (!visit[edge[cur][i]]) {
			dfs(edge[cur][i], cur);
			f[cur][1] += min(f[edge[cur][i]][0], f[edge[cur][i]][1]);
			f[cur][0] += f[edge[cur][i]][1];
		}
	}
}

void find_loop(const int cur, const int father) {
	instack[cur] = u[cur] = true;
	for (int i=0; i<(signed)edge[cur].size(); i++) {
		if (edge[cur][i] == father) continue;
		if (instack[edge[cur][i]]) {
			s = cur;
			t = edge[cur][i];
			throw 0;
		}
		else find_loop(edge[cur][i], cur);
	}
	instack[cur] = false;
}

int main() {
	freopen("1832.in" , "r", stdin );
	freopen("1832.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &m[i]);
		for (int j=0, to; j<m[i]; j++) {
			scanf("%d", &to);
			edge[i].push_back(to);
		}
	}

	try {
		find_loop(1, -1);
	}
	catch(int e) {}


	init();
	dfs(s, -1);
	ans = f[s][1];
	init();
	dfs(t, -1);
	ans = min(ans, f[t][1]);

	printf("%d\n", ans);

	return 0;
}
