// 1778.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::swap;
using std::min;

struct NODE { int x, y; };
NODE from, to, tele[6][2];
long long ans;
int r;

long long dis(const NODE from, const NODE to) {
	return (long long)abs(from.x - to.x) + abs(from.y - to.y);
}

long long tim(const int fir, const int sec, const int thi) {
	long long ret = 0;
	if (fir != -1) {
		ret += dis(from, tele[fir][0]) + 10;
		if (sec != -1) {
			ret += dis(tele[fir][1], tele[sec][0]) + 10;
			if (thi != -1) {
				ret += dis(tele[sec][1], tele[thi][0]) + 10;
				ret += dis(tele[thi][1], to);
			}
			else ret += dis(tele[sec][1], to);
		}
		else ret += dis(tele[fir][1], to);
	}
	else ret += dis(from, to);
	return ret;
}

int main() {
	freopen("1778.in" , "r", stdin );
	freopen("1778.out", "w", stdout);

	scanf("%d", &r);
	while (r --) {
		scanf("%d %d", &from.x, &from.y);
		scanf("%d %d", &to.x, &to.y);
		scanf("%d %d %d %d", &tele[0][0].x, &tele[0][0].y, &tele[0][1].x, &tele[0][1].y);
		scanf("%d %d %d %d", &tele[1][0].x, &tele[1][0].y, &tele[1][1].x, &tele[1][1].y);
		scanf("%d %d %d %d", &tele[2][0].x, &tele[2][0].y, &tele[2][1].x, &tele[2][1].y);
		for (int i=3; i<6; i++) {
			tele[i][0] = tele[i-3][1];
			tele[i][1] = tele[i-3][0];
		}
		ans = tim(-1, -1, -1);
		for (int i=0; i<6; i++) {
			ans = min(ans, tim(i, -1, -1));
			for (int j=0; j<6; j++) {
				if (i == j || abs(j-i) == 3) continue;
				ans = min(ans, tim(i, j, -1));
				for (int k=0; k<6; k++)
					if (k != i && k != j && abs(k-i)!=3 && abs(k-j)!=3)
						ans = min(ans, tim(i, j, k));
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
