// 1964.cpp
#include <cstring>
#include <cstdio>

const int MAXN = 55;
char word[MAXN];
int maxc, len, maxs=1, ans, status[MAXN], count[MAXN][26], maxcnt[MAXN];
char maxwrd[MAXN];

int get_pos(const int pos, const int len, const int deep) {
	if (!deep) return pos;
	if (pos > len - pos - 1) return get_pos(len - pos - 1, len / 2, deep - 1);
	else                     return get_pos(pos          , len / 2, deep - 1);
}

int work(const int score) {
	int change = 0;
	for (int i=0; i<len; i++)
		status[i] = get_pos(i, len, score);

	memset(count , 0, sizeof(count ));
	memset(maxcnt, 0, sizeof(maxcnt));
	for (int i=0; i<len; i++) {
		count[status[i]][word[i]-'a'] ++;
		if (count[status[i]][word[i]-'a'] > maxcnt[status[i]]) {
			maxcnt[status[i]] = count[status[i]][word[i]-'a'];
			maxwrd[status[i]] = word[i];
		}
	}
	for (int i=0; i<len; i++)
		if (word[i] != maxwrd[status[i]])
			change ++;
	return change;
}

int main() {
	freopen("1964.in" , "r", stdin );
	freopen("1964.out", "w", stdout);

	scanf("%s %d", word, &maxc);
	len = strlen(word);
	for (int i=len; !(i%2); i/=2, maxs++);

	for (int i=maxs; i>=0; i--)
		if (i == 0 || work(i) <= maxc) {
			printf("%d\n", i);
			break;
		}

	return 0;
}
