// 1912.cpp
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

const long long INF  = 0xFFFFFFFFFFF;
const int MAXN = 55;
int r, n, p, score[MAXN], appead[MAXN], unknown[MAXN], unknowns, untot, maxx;
long long ans, ans2, ans3;

int main() {
	freopen("1912.in" , "r", stdin );
	freopen("1912.out", "w", stdout);

	scanf("%d", &r);
	while (r--) {
		untot = maxx = unknowns = 0;
		ans = ans3 = ans2 = INF;
		scanf("%d %d", &n, &p);
		for (int i=1; i<=n; i++)
			appead[i] = false;
		for (int i=0; i<n; i++) {
			scanf("%d", &score[i]);
			appead[score[i]] = true;
			maxx = max(maxx, score[i]);
		}
		for (int i=1; i<=n; i++)
			if (!appead[i])
				untot += (unknown[unknowns++] = i);
		if (maxx) ans = (p - 1) / maxx + 1;
		else      ans = INF;
		if (!unknowns) ans2 = INF;
		else {
			int times = p / untot;
			long long cur = times * untot;
			ans2 = times * unknowns;
			if (maxx) ans3 = ans2 + (p - cur - 1) / maxx + 1;
			for (; cur<p; ans2++)
				cur += unknown[ans2 % unknowns];
		}
		printf("%lld\n", min(ans2, min(ans, ans3)));
	}

	return 0;
}
