// 1962.cpp
#include <cstdio>

const int MAXN = 8192;
int r;
long long pow[16], num[MAXN];

int main() {
	freopen("1962.in" , "r", stdin );
	freopen("1962.out", "w", stdout);

	pow[0] = 1;
	for (int i=1; i<=15; i++)
		pow[i] = pow[i-1] * 5;
	
	for (int i=1, k=1; k<MAXN; i++)
		for (int t=k, j=0; j<t && k<MAXN; j++, k++)
			num[k] = num[j] + pow[i];

	scanf("%d", &r);
	for (int i=0, t; i<r; i++) {
		scanf("%d", &t);
		printf("%lld\n", num[t]);
	}

	return 0;
}
