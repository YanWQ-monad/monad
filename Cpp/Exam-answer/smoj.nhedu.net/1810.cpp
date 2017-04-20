// 1810.cpp
#include <cstdio>

const int MAXN   = 510;
const int MAXM   = 510;
const int PRIME1 = 6291469;
const int PRIME2 = 12289;
const int ADDER  = 97;
int n, m;
char nor[MAXN][MAXM], ill[MAXN][MAXM];
int sum[MAXN][MAXM], kum[MAXN][MAXM], power[MAXM];
bool exist[PRIME2];
int table[PRIME2];

int ToInt(const char c) {
	switch(c) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		default : throw;
	}
}

int Hash(const int value) {
	int hash = value % PRIME2, add = value % ADDER + 1;
	while (table[hash] != value && exist[hash]) {
		hash += add;
		if (hash >= PRIME2) hash -= PRIME2;
	}
	return hash;
}

bool TryLen(const int len) {
	for (int bgn=1; bgn<=m-len+1; bgn++) {
		const int l = bgn, r = bgn + len - 1;
		bool can = true;
		for (int i=0; i<PRIME2; i++) {
			table[i] = -1;
			exist[i] = false;
		}
		for (int j=0; j<n; j++) {
			int dataHash = (sum[j][r] - (int)((long long)sum[j][l-1] * power[len] % PRIME1) + PRIME1) % PRIME1;
			int hash = Hash(dataHash);
			table[hash] = dataHash;
			exist[hash] = true;
		}
		for (int j=0; j<n; j++) {
			int dataHash = (kum[j][r] - (int)((long long)kum[j][l-1] * power[len] % PRIME1) + PRIME1) % PRIME1;
			int hash = Hash(dataHash);
			if (exist[hash]) {
				can = false;
				break;
			}
		}
		if (can) return true;
	}
	return false;
}

int main() {
	freopen("1810.in" , "r", stdin );
	freopen("1810.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++)
		scanf("%s", nor[i]);
	for (int i=0; i<n; i++)
		scanf("%s", ill[i]);

	power[0] = 1;
	for (int i=1; i<=m; i++)
		power[i] = (power[i-1] * 4) % PRIME1;
	for (int i=0; i<n; i++)
		for (int j=1; j<=m; j++) {
			sum[i][j] = (sum[i][j-1] * 4 + ToInt(nor[i][j-1])) % PRIME1;
			kum[i][j] = (kum[i][j-1] * 4 + ToInt(ill[i][j-1])) % PRIME1;
		}

	int l=0, r=m+1, mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (TryLen(mid)) r = mid;
		else             l = mid;
	}
	printf("%d\n", r);


	return 0;
}
