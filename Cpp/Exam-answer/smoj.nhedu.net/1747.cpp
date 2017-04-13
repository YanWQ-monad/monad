// 1747.cpp
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using std::sort;

const int MAXN = 60;
struct TMP { char a, b; } sc[MAXN];
int k, n, ans=0;
char stA[MAXN], stB[MAXN];

int cmp(const TMP lhs, const TMP rhs) {
	return abs(lhs.a - lhs.b) > abs(rhs.a - rhs.b);
}

int main() {
	freopen("1747.in" , "r", stdin );
	freopen("1747.out", "w", stdout);
	
	scanf("%s %s %d", stA, stB, &k);
	n = strlen(stA);
	for (int i=0; i<n; i++) {
		sc[i].a = stA[i];
		sc[i].b = stB[i];
	}
	sort(sc, sc+n, cmp);
	for (int i=0; i<n; i++) {
		stA[i] = sc[i].a;
		stB[i] = sc[i].b;
	}
	
	for (int i=0; i<k; i++) {
		if (stA[i] != stB[i])
			stA[i] = stB[i];
		else {
			if (stB[i] == 'z') stA[i] = 'y';
			else               stA[i] = stB[i] + 1;
		}
	}
	
	for (int i=0; i<n; i++)
		ans += abs(stA[i] - stB[i]);
	
	printf("%d\n", ans);
	
	return 0;
}
