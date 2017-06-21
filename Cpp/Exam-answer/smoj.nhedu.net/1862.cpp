// 1862.cpp
#include <cstdio>

const int MAXN = 100010;
int r, n, m, queue[MAXN], head, tail, ans[MAXN];

void init() {
	for (int i=0; i<MAXN; i++)
		ans[i] = -1;
	head = tail = 0;
}

void bfs() {
	queue[tail++] = n;
	ans[n] = 0;
	while (head < tail) {
		int cur = queue[head++];
		for (int i=2; i*i<=cur; i++) {
			if (cur % i) continue;
			if (cur+i<=m && ans[cur+i] == -1) {
				queue[tail++] = cur + i;
				ans[cur+i] = ans[cur] + 1;
			}
			if (cur+(cur/i)<=m && ans[cur+(cur/i)] == -1) {
				queue[tail++] = cur + (cur/i);
				ans[cur+(cur/i)] = ans[cur] + 1;
			}
		}
	}
}

int main() {
	freopen("1862.in" , "r", stdin );
	freopen("1862.out", "w", stdout);
	
	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &n, &m);
		init();
		bfs();
		printf("%d\n", ans[m]);
	}

	return 0;
}
