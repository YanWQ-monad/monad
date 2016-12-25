// 1534.cpp
#include <algorithm>
#include <cstdio>
using std::abs;

const int MAXN = 30010;
int t, x, y, father[MAXN], pos[MAXN], tail[MAXN];
char buf[10];

int findAncestor(const int node) {
	if (father[node]==node) return node;
	int fa = findAncestor(father[node]);
	if (fa != father[node]) {
		pos[node] += pos[father[node]];
		father[node] = fa;
	}
	return fa;
}

void merge(const int x, const int y) {
	int tx = findAncestor(x),
	    ty = findAncestor(y);
	if (tx != ty) {
		father[tx]=ty;
		findAncestor(tail[ty]);
		pos[tx] = pos[tail[ty]] + 1;
		tail[ty] = tail[tx];
	}
}

int main() {
	freopen("1534.in" , "r", stdin );
	freopen("1534.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++) {
		tail[i] = father[i] = i;
		pos[i] = 0;
	}
	
	scanf("%d", &t);
	while (t--) {
		scanf("%s %d %d", buf, &x, &y);
		if (buf[0]=='M') {
			merge(x, y);
		}
		else {
			if (findAncestor(x) == findAncestor(y)) {
				printf("%d\n", abs(pos[x] - pos[y]) - 1);
			}
			else puts("-1");
		}
	}
	return 0;
}
