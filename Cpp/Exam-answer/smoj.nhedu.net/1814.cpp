// 1814.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::swap;

const int MAXN  = 100010;
const int PRIME = 1000007;
const int ADDER = 193;

struct SNOW { int d[6]; };
int n,table[PRIME];
bool exist[PRIME];
SNOW data[PRIME], snow[MAXN];

int Hash(const int value) {
	int hash = value % PRIME, add = value % 193 + 1;
	while (table[hash] != value && exist[hash]) {
		hash += add;
		if (hash >= PRIME) hash -= PRIME;
	}
	return hash;
}

bool compare(const SNOW lhs, const SNOW rhs) {
	return !memcmp(&lhs, &rhs, sizeof(SNOW));
}

int CalcHash(const SNOW snow) {
	int hash = 0;
	for (int i=0; i<6; i++)
		hash = ((hash << 4) + snow.d[i]) % 12582917;
	return hash;
}

SNOW next(const SNOW snow) {
	SNOW ret;
	for (int i=0; i<5; i++)
		ret.d[i] = snow.d[i+1];
	ret.d[5] = snow.d[0];
	return ret;
}

bool HaveSame(SNOW snow) {
	for (int i=0; i<6; i++) {
		int hash = Hash(CalcHash(snow)), add = snow.d[0] % 193 + 1;
		while (exist[hash]) {
			if (compare(snow, data[hash])) return true;
			hash += add;
			if (hash >= PRIME) hash -= PRIME;
		}
		snow = next(snow);
	}
	for (int i=0; i<3; i++)
		swap(snow.d[i], snow.d[5-i]);
	for (int i=0; i<6; i++) {
		int hash = Hash(CalcHash(snow)), add = snow.d[0] % 193 + 1;
		while (exist[hash]) {
			if (compare(snow, data[hash])) return true;
			hash += add;
			if (hash >= PRIME) hash -= PRIME;
		}
		snow = next(snow);
	}
	return false;
}

void Add(SNOW snow) {
	int hash = Hash(CalcHash(snow)), add = snow.d[0] % 193 + 1;
	while (exist[hash]) {
		hash += add;
		if (hash >= PRIME) hash -= PRIME;
	}
	data [hash] = snow;
	exist[hash] = true;
	table[hash] = CalcHash(snow);
}

int main() {
	freopen("1814.in" , "r", stdin );
	freopen("1814.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<6; j++)
			scanf("%d", &snow[i].d[j]);
		if (HaveSame(snow[i])) {
			puts("Twin snowflakes found.");
			return 0;
		}
		Add(snow[i]);
	}
	puts("No two snowflakes are alike.");


	return 0;
}
