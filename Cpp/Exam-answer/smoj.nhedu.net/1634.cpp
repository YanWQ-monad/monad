// 1634.cpp
#include <iostream>
#include <cstring>
#include <cstdio>

const int MAXN = 40;
long long p, q=1;
int n;
char st[MAXN];

int main() {
	freopen("1634.in" , "r", stdin );
	freopen("1634.out", "w", stdout);

	std::cin >> &st[1] >> p;
	//scanf("%s %lld", &st[1], &p);
	n = strlen(&st[1]);
	while (q * n * 2 < p)
		q *= 2;
	q *= n;


	while (p > n) {
		if (p < q) {
			q /= 2;
			continue;
		}
		if (p == q + 1) p = p - 1;
		else            p = p - q - 1;
		q /= 2;
	}

	//printf("%c\n", st[(int)p]);
	std::cout << st[(int)p] << std::endl;

	return 0;
}
