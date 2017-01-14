// 1592.cpp
// -------------------------------------------------------------------------------------------------------
//         Kruskal
#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 110;
struct EDGE {int from, to, len;} edge[MAXN*MAXN];
int n, father[MAXN], f[MAXN][MAXN], TotEdge=0, ans=0;
int findAncestor(const int node) {
	return (father[node]==node)? (node):(father[node]=findAncestor(father[node]));
}

void merge(const int x, const int y) {
	father[findAncestor(x)] = findAncestor(y);
}

int EdgeSort(const EDGE lhs, const EDGE rhs) {
	return lhs.len < rhs.len;
}

void read() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &f[i][j]);
}

void toEdge() {
	TotEdge=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++) {
			edge[TotEdge].from = i;
			edge[TotEdge].to = j;
			edge[TotEdge].len = f[i][j];
			TotEdge++;
		}
}

void buildTree() {
	int edges=0;
	for (int i=0; i<TotEdge && edges<n-1; i++) {
		if (findAncestor(edge[i].from) != findAncestor(edge[i].to)) {
			ans += f[edge[i].from][edge[i].to];
			merge(edge[i].from, edge[i].to);
			edges++;
		}
	}
}

int main() {
	freopen("1592.in" , "r", stdin );
	freopen("1592.out", "w", stdout);
	
	for (int i=0; i<MAXN; i++)
		father[i] = i;
	
	read();
	toEdge();
	sort(edge, edge+TotEdge, EdgeSort);
	buildTree();
	printf("%d\n", ans);
	
	return 0;
}

// -----------------------------------------------------------------------------------------------------------------
//       Prim
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;

template<typename T, const int MAX_LEN>
class mWinnerTree {
 protected:
	int len, k;
	bool isNone[MAX_LEN];
	T mi[MAX_LEN], ma[MAX_LEN];
	int ipos[MAX_LEN], apos[MAX_LEN];
 public:
 	void clear() {
 		for (int i=0; i<MAX_LEN; i++)
			isNone[i] = true;
		for (int i=k; i<2*k; i++)
			ipos[i] = apos[i] = i - k + 1;
	}
	mWinnerTree(const int size=0) : k(1), len(size) {
		while (k < size) k <<= 1;
		clear();
	}
	void setLen(const int size) {
		k = 1;
		len = size;
		while (k < size) k <<= 1;
		clear();
	}
	T edit(const int _pos, const T con) {
		int pos = _pos + k - 1, temp;
		ma[pos] = mi[pos] = con;
		isNone[pos] = false;
		while (pos >>= 1) {
			if (isNone[pos*2] && isNone[pos*2+1])
				isNone[pos] = true;
			else {
				isNone[pos] = false;
				if (isNone[pos*2] || isNone[pos*2+1]) {
					if (isNone[pos*2]) temp = pos*2+1;
					else               temp = pos * 2;
					mi[pos] = mi[temp];
					ma[pos] = ma[temp];
					ipos[pos] = ipos[temp];
					apos[pos] = apos[temp];
				}
				else {
					mi[pos] = ::min(mi[pos*2], mi[pos*2+1]);
					ma[pos] = ::max(ma[pos*2], ma[pos*2+1]);
					apos[pos] = apos[(ma[pos*2] >= ma[pos*2+1])? (pos*2):(pos*2+1)];
					ipos[pos] = ipos[(mi[pos*2] <= mi[pos*2+1])? (pos*2):(pos*2+1)];
				}
			}
		}
		return con;
	}
	T operator[](const int pos) {
		return ma[pos + k - 1];
	}
	bool exist(const int pos) const {
		return !isNone[pos + k - 1];
	}
	T min() const {
		return mi[1];
	}
	T min_pos() const {
		return ipos[1];
	}
	T max() const {
		return ma[1];
	}
	T max_pos() const {
		return apos[1];
	}
};

const int INF = 0x3FFFFFFF;
const int MAXN = 110;
mWinnerTree<int, MAXN*4> tree;

int n, len[MAXN][MAXN];
bool used[MAXN];

int prim() {
	int ret = 0;
	tree.edit(1, 0);
	for (int trees=0, to; trees<n; trees++) {
		to = tree.min_pos();
		ret += tree.min();
		used[to] = true;
		tree.edit(to, INF);
		for (int i=1; i<=n; i++)
			if (len[to][i] != 0 && !used[i] && (!tree.exist(i) || len[to][i]<tree[i]))
				tree.edit(i, len[to][i]);
	}
	return ret;
}

int main() {
	freopen("1592.in" , "r", stdin );
	freopen("1592.out", "w", stdout);

	scanf("%d", &n);
	tree.setLen(n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &len[i][j]);

	printf("%d\n", prim());

	return 0;
}
