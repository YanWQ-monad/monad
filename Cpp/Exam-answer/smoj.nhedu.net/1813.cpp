// 1813.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>

const int MAXN   = 16000010;
const int PRIME  = 50331653;

int c, len, sum[MAXN], power=1, ans=0, appead[256], cnt=0, tmp=0;
bool exist[PRIME];
char st[MAXN];

int main() {
	freopen("1813.in" , "r", stdin );
	freopen("1813.out", "w", stdout);

	scanf("%d %*d %s", &c, st);
	len = strlen(st);
	for (int i=0; i<len; i++) {
		if (!appead[(int)st[i]])
			appead[(int)st[i]] = ++cnt;
		sum[i] = appead[(int)st[i]] - 1;
	}
	for(int i=0; i<c; i++) {
	    tmp   = (tmp * cnt + sum[i]) % PRIME;
	    power = (i<c-1? (power * cnt % PRIME) : power);
	}
	exist[tmp] = true;

	for (int i=c; i<len; i++) {
		tmp = ((tmp - sum[i-c] * power % PRIME + PRIME) % PRIME * cnt + sum[i]) % PRIME;
		if (!exist[tmp]) {
			ans ++;
			exist[tmp] = true;
		}
	}

	printf("%d\n", ans+1);


	return 0;
}
