// 1812.cpp
#include <algorithm>
#include <cstdio>

const int PRIME = 98317;
int table[PRIME], ans = 0, data[PRIME], a[5];

int Hash(const int value) {
	int pos;
	if (value < 0) pos = -value;
	else           pos =  value;
	int hash = pos % PRIME, add = pos % 193 + 1;
	while (table[hash] != value && data[hash] != 0) {
		hash += add;
		if (hash >= PRIME) hash -= PRIME;
	}
	return hash;
}

int main() {
	freopen("1812.in" , "r", stdin );
	freopen("1812.out", "w", stdout);

	for (int i=0; i<5; i++)
		scanf("%d", &a[i]);
	for (int i=-50; i<=50; i++)
		for (int j=-50; j<=50; j++)
			if (i != 0 && j != 0) {
				int cur = (long long)a[0] * i * i * i + a[1] * j * j * j;
				int hash = Hash(cur);
				table[hash] = cur;
				data[hash] ++;
			}
	for (int i=-50; i<=50; i++)
		for (int j=-50; j<=50; j++)
			for (int k=-50; k<=50; k++)
				if (i != 0 && j != 0 && k != 0) {
					int cur = (long long)a[2] * i * i * i + a[3] * j * j * j + a[4] * k * k * k;
					int hash = Hash(-cur);
					ans += data[hash];
				}
	printf("%d\n", ans);

	return 0;
}
