// 1965.cpp
#include <cstdlib>
#include <cstring>
#include <cstdio>

int r, d, now;
size_t min_len;
char com[100], out[100];

int basic_gcd(const int a,const int b) {
	if (a % b) return basic_gcd(b, a % b);
	else       return b;
}

int gcd(const int lhs, const int rhs, char *com, const size_t cur_len = 0) {
	if (cur_len > min_len) return 2;
	if (lhs > rhs) {
		com[cur_len] = 'X';
		return gcd(lhs - rhs, rhs, com, cur_len+1) + 1;
	}
	else if (rhs > lhs) {
		com[cur_len] = 'Y';
		return gcd(lhs, rhs - lhs, com, cur_len+1) + 1;
	}
	else return 0;
}

bool fuck_zidianxu(const char *lhs, const char *rhs) {
	int len = strlen(lhs);
	for (int i=0; i<len; i++)
		if (lhs[len-i-1] != rhs[i])
			return lhs[len-i-1] == 'X';
	return rand() % 1; // never happens
}

int main() {
	freopen("1965.in" , "r", stdin );
	freopen("1965.out", "w", stdout);

	scanf("%d", &r);
	while (r--) {
		scanf("%d", &d);
		min_len = 100;
		memset(out, '\0', 100);
		for (int i=1; i<d; i++) {
			memset(com, '\0', 100);
			if (basic_gcd(d, i) != 1)
				continue;
			size_t len = gcd(d, i, com);
			com[len] = '\0';
	//		printf("DEBUG - %s - Y=%d, len=%u\n", com, i, len);
			if (len < min_len || (len == min_len && fuck_zidianxu(com, out))) {
				min_len = len;
				now = i;
				for (size_t i=0; i<min_len; i++)
					out[i] = com[min_len - i - 1];
				out[min_len] = '\0';
			}
		}
	//	printf("%s - Y=%d\n", out, now);
		puts(out);
	}

	return 0;
}
