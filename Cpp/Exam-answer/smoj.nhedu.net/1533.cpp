// 1533.cpp
#include <cstdio>

const int HASH_MOD = 100007;
class mHash {
 protected:
	int hash_array[HASH_MOD], hash_table[HASH_MOD];
	int hash(const int con) const {
		int hash_map = con % HASH_MOD;
		while (hash_table[hash_map] != -1 && hash_table[hash_map] != con) {
			hash_map++;
			if (hash_map >= HASH_MOD) hash_map = 0;
		}
		return hash_map;
	}
 public:
 	mHash() {
 		for (int i=0; i<HASH_MOD; i++)
 			hash_array[i] = hash_table[i] = -1;
 	}
	virtual ~mHash() {}
	
	bool exist(const int pos) const {
		if (pos<0) return false;
		const int temp = hash(pos);
		return hash_table[temp] == pos;
	}
	int& operator[](const int pos)       {
		int hash_map = hash(pos);
		hash_table[hash_map] = pos;
		return hash_array[hash_map];
	}
	int  operator[](const int pos) const {
		return hash_array[hash(pos)];
	}
};

int l, n, ans;
char buf[5];
mHash father;
int findAncestor(const int node) {
	return (father[node]==node)? (node):(father[node]=findAncestor(father[node]));
}

void merge(const int x, const int y) {
	father[findAncestor(x)] = findAncestor(y);
}

int main() {
	freopen("1533.in" , "r", stdin );
	freopen("1533.out", "w", stdout);
	
	scanf("%d %d", &l, &n);
	l++;
	ans=n;
	for (int i=0, x, y; i<n; i++) {
		scanf("%d %d %s", &x, &y, buf);
		x--;
		if (!father.exist( x )) father[ x ] =  x ;
		if (!father.exist( y )) father[ y ] =  y ;
		if (!father.exist(x+l)) father[x+l] = x+l;
		if (!father.exist(y+l)) father[y+l] = y+l;
		if (buf[0] == 'o') {
			if (findAncestor(x) == findAncestor(y  )) {
				ans=i;
				break;
			}
			merge(x  , y+l);
			merge(x+l, y  );
		}
		else {
			if (findAncestor(x) == findAncestor(y+l)) {
				ans=i;
				break;
			}
			merge( x ,  y );
			merge(x+l, y+l);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
