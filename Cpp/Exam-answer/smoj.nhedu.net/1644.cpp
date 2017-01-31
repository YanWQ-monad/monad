// 1644.cpp
#include <cstdio>

const int MAXN = 3010;
const int MAXM = 3010;
struct PAIR { int s, t; } pair[MAXM];
int n, m, father[MAXN];
bool died[MAXN];

int findA(const int node) {
	return (father[node] == node)? (node) : (father[node] = findA(father[node]));
}

void merge(const int lhs, const int rhs) {
	father[findA(lhs)] = findA(rhs);
}

int main() {
	freopen("1644.in" , "r", stdin );
	freopen("1644.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++)
		scanf("%d %d", &pair[i].s, &pair[i].t);

	for (int i=0, a, r; i<n; i++) {
		for (int i=0; i<MAXN; i++)
			father[i] = i;
		for (int j=0; j<m; j++)
			if (!died[pair[j].s] && !died[pair[j].t])
				merge(pair[j].s, pair[j].t);
		r = -1;
		for (int i=1; i<=n; i++)
			if (!died[i]) {
				if (r == -1) r = findA(i);
				else if (r != findA(i)) {
					r = -2;
					break;
				}
			}
		puts((r == -2)? "NO":"YES");
		scanf("%d", &a);
		died[a] = true;
	}

	return 0;
}
