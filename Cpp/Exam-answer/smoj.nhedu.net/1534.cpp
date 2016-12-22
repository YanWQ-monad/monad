#include <algorithm>
#include <cstdio>
using std::abs;

#define clean(arr, con, len) for (int i=0; i<len; i++) arr[i]=con;
const int MAXN = 30050;
int t, father[MAXN], d[MAXN], s[MAXN];
char buf[5];

int findAncestor(const int x) {
	if (father[x] == x) return x;
	else {
	    int ret = findAncestor(father[x]);
		d[x] += d[father[x]];
		return father[x] = ret;
	}
}

void merge(int lhs, int rhs) {
	lhs = findAncestor(lhs);
	rhs = findAncestor(rhs);
	if (lhs != rhs) {
		d[lhs] = s[rhs];
		s[rhs] += s[lhs];
		father[lhs] = rhs;
	}
}

int main() {
	freopen("1534.in" , "r", stdin );
	freopen("1534.out", "w", stdout);
	clean(father, i, MAXN);
	clean(s     , 1, MAXN);
	clean(d     , 0, MAXN);
	scanf("%d", &t);
	for (int i=0, a, b; i<t; i++) {
		scanf("%s %d %d", buf, &a, &b);
		if (buf[0] == 'M') merge(a, b);
		else {
			if (findAncestor(a) != findAncestor(b)) puts("-1");
			else printf("%d\n", abs(d[a] - d[b]) - 1);
		}
	}
	return 0;
}
