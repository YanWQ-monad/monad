// 1772.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int MAXN = 1010;
int n, num[11], d=0;
long long ans=0, map[11], wei[11];

int main() {
	freopen("1772.in" , "r", stdin );
	freopen("1772.out", "w", stdout);

	scanf("%d", &n);

	for (int tmp=n; tmp; d++, tmp /= 10);
	for (long long i=1, last=0, ans=0, p=1, tmp=n; tmp; i++) {
		for (int j=1; j<=9; j++)
			ans += j * p + last;
		last = ans;
		map[d - i + 1] = ans;
		num[d - i + 1] = tmp % 10;
		wei[d - i + 1] = p;
		::ans += tmp % 10;
		tmp /= 10;
		p *= 10;
	}

	for (int i=1, l=0; i<=d; i++) {
		for (int j=0; j<num[i]; j++)
			ans += (long long)(l + j) * wei[i] + map[i+1];
		l += num[i];
	}
	printf("%lld\n", ans);

	return 0;
}
