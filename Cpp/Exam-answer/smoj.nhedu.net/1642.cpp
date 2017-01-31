// 1642.cpp
#include <algorithm>
#include <cstdio>
using std::swap;
using std::max;
using std::min;

const int INF  = 0x7FFFFFFF;
const int MAXN = 50010;
int n, l, r, u, b, mnd[4][3], q[12], mjs=0, L, R, U, B, ans=INF;
bool in[MAXN], died[MAXN];
struct STU { int x, y; } stu[MAXN];
int cmp1(const STU lhs, const STU rhs) { return lhs.x < rhs.x; }
int cmp2(const STU lhs, const STU rhs) { return lhs.x > rhs.x; }
int cmp3(const STU lhs, const STU rhs) { return lhs.y < rhs.y; }
int cmp4(const STU lhs, const STU rhs) { return lhs.y > rhs.y; }
int (*cmps[4])(const STU, const STU) = { cmp1, cmp2, cmp3, cmp4 };

void TryAdd(const int pos) {
	for (int i=0; i<4; i++) {
		if (mnd[i][2] == 0 || cmps[i]( stu[mnd[i][2]], stu[pos] )) {
			mnd[i][2] = pos;
			for (int j=2; j; j--)
				if (mnd[i][j-1] == 0 || cmps[i]( stu[mnd[i][j-1]], stu[mnd[i][j]] ))
					swap(mnd[i][j-1], mnd[i][j]);
		}
	}
}

void Update(const int pos) {
	if (l == -1) {
		l = r = stu[pos].x;
		u = b = stu[pos].y;
	}
	else {
		l = min(l, stu[pos].x);
		r = max(r, stu[pos].x);
		b = min(b, stu[pos].y);
		u = max(u, stu[pos].y);
	}
}

int main() {
	freopen("1642.in" , "r", stdin );
	freopen("1642.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d %d", &stu[i].x, &stu[i].y);
		TryAdd(i);
	}

	for (int i=0; i<4; i++)
		for (int j=0; j<3; j++)
			if (mnd[i][j] != 0 && !in[mnd[i][j]]) {
				q[mjs ++] = mnd[i][j];
				in[mnd[i][j]] = true;
			}

	for (int i=0; i<mjs; i++)
		died[q[i]] = true;
	l = r = u = b = -1;
	for (int i=1; i<=n; i++)
		if (!died[i])
			Update(i);
	if (mjs >= 12) throw 1;
	L = l; R = r; U = u; B = b;

	for (int i=0, cnt=0; i<(1 << mjs); i++, cnt=0) {
		for (int j=0; j<mjs; j++)
			if ((i & (1 << j)) > 0 && ++cnt > 3)
				break;
		if (cnt > 3) continue;
		
		l = L; r = R; b = B; u = U;
		for (int j=0; j<mjs; j++)
			if ((i & (1 << j)) == 0)
				Update(q[j]);

		ans = min(ans, (r - l) * (u - b));
	}

	printf("%d\n", ans);

	return 0;
}
