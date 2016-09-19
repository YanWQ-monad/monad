// 1403.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::sort;
using std::max;

int n, ans = 0;
char st[20][21], temp;
int greedy(int kills, int line) {
	int sum = 0, temp[20], tp[21];
	memset(temp, 0, sizeof(temp));
	memset(tp, 0, sizeof(tp));
	for (int i=0; i<20; i++)
		if (line & (1 << i))
			for (int j=0; j<20; j++)
				temp[j] += st[i][j] == '#';
	for (int i=0; i<20; i++)
		tp[temp[i]] ++;
	for (int i=20; i>=0; i--)
		if (kills >= tp[i]) {sum += tp[i] * i; kills -= tp[i];}
		else {sum += kills * i; break;}
	return sum;
}
int main() {
	freopen("1403.in", "r", stdin);
	freopen("1403.out", "w", stdout);
	scanf("%d",&n);
	for (int i=0; i<20; i++)
		for (int j=0; j<20; j++)
			while (st[i][j] != '#' && st[i][j] !='.')
				st[i][j] = getchar();
	for (int i=1, line_kill, j; i<(1<<20); i++) {
		for (line_kill = j = 0; j<20; j++)
			line_kill += bool(i & (1 << j));
		if (n-line_kill <= 0 || n-line_kill > 20) continue;
		ans = max(ans, greedy(n-line_kill, i));
	}
	printf("%d\n",ans);
	return 0;
}
