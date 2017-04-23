// 1829.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::max;
using std::min;

const int INF   = 0xFFFFFFF;
const int MAXN  = 100010;
const int MAXK  = 32;
const int PRIME = 786433;
const int ADDER = 193;

template<typename table_T, typename data_T>
class mHash {
 private:
	table_T table[PRIME];
	data_T data[PRIME];
	int Hash(const table_T value) const {
		int hash = abs(value.GetValue()) % PRIME, add = abs(value.GetValue()) % ADDER + 1;
		while (memcmp(table+hash, &value, sizeof(table_T)) && data[hash] != INF)
			if ((hash += add) >= PRIME)
				hash -= PRIME;
		return hash;
	}

 public:
 	mHash() {
 		for (int i=0; i<PRIME; i++)
 			data[i] = INF;
 	}
	void setData(const table_T value, const data_T d) {
		int hash = Hash(value);
		table[hash] = value;
		data [hash] = d;
	}
	bool exist(const table_T value) const {
		int hash = Hash(value);
		return data[hash] != INF;
	}
	data_T GetData(const table_T value) const {
		int hash = Hash(value);
		return data[hash];
	}
};

struct TABLE {
	int data, sum[MAXK];
	int GetValue() const {
		return data;
	}
} tmp;
mHash<TABLE, int> hash;
int n, k, a[MAXN], ans=0, sum[MAXN][MAXK];

TABLE GetHash(const int pos) {
	TABLE ret;
	for (int i=0; i<MAXK; i++)
		ret.sum[i] = 0;
	ret.data = 0;
	for (int i=1; i<k; i++)
		ret.data = (int)(((long long)ret.data * n + (ret.sum[i-1] = sum[pos][i] - sum[pos][i-1])) % 805306457);
	return ret;
}

int main() {
	freopen("1829.in" , "r", stdin );
	freopen("1829.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		for (int j=0; j<k; j++)
			sum[i][j] = sum[i-1][j] + !!(a[i]&(1<<j));
	}

	hash.setData(tmp, 0);
	for (int i=1; i<=n; i++) {
		tmp = GetHash(i);
		if (hash.exist(tmp)) ans = max(ans, i-hash.GetData(tmp));
		else                 hash.setData(tmp, i);
	}
	printf("%d\n", ans);


	return 0;
}
