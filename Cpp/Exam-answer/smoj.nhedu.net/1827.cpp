// 1827.cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using std::min;

const int INF   = 0xFFFFFFF;
const int PRIME = 6151;
const int MAXN  = 2010;
const int ADDER = 97;
int n, last, num[MAXN], ans=INF;

class mHash {
 private:
	int table[PRIME], data[PRIME];
	int Hash(const int value) const {
		int hash = abs(value) % PRIME, add = abs(value) % ADDER + 1;
		while (table[hash] != value && data[hash] != -1)
			if ((hash += add) >= PRIME)
				hash -= PRIME;
		return hash;
	}

 public:
 	mHash() {
 		for (int i=0; i<PRIME; i++)
 			data[i] = -1;
 	}
	void setData(const int value, const int d) {
		int hash = Hash(value);
		table[hash] = value;
		data [hash] = d;
	}
	bool exist(const int value) const {
		int hash = Hash(value);
		return data[hash] != -1;
	}
	int GetData(const int value) const {
		if (!exist(value)) return INF;
		int hash = Hash(value);
		return data[hash];
	}
	int operator[](const int pos) const {
		if (data[pos] == -1) return INF;
		return data[pos];
	}
};

mHash f[MAXN];

int main() {
	freopen("1827.in" , "r", stdin );
	freopen("1827.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &num[i]);
	if (n == 1) {
		puts("1");
		return 0;
	}

	for (int i=1; i<=n; i++) {
		for (int bgn=1; bgn<i; bgn++) {
			const int dif = num[i] - num[bgn];
			const int del = i - bgn - 1;
			if (del + bgn - 1 < f[i].GetData(dif))
				f[i].setData(dif, del + bgn - 1);
			if (bgn != 1)
				if (f[bgn].exist(dif)) {
					int last = f[bgn].GetData(dif);
					if (last + del < f[i].GetData(dif))
						f[i].setData(dif, last + del);
				}
		}
	}

	for (int i=1; i<=n; i++)
		for (int j=0; j<PRIME; j++)
			ans = min(ans, f[i][j]+n-i);
	printf("%d\n", n-ans);

	return 0;
}
