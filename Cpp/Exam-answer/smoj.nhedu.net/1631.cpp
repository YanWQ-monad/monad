// 1631.cpp
#include <algorithm>
#include <cstring>
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
	mWinnerTree(const int size = 0) : len(size), k(1) {
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
					apos[pos] = apos[(ma[pos*2] < ma[pos*2+1])? (pos*2+1):(pos*2)];
					ipos[pos] = ipos[(mi[pos*2] < mi[pos*2+1])? (pos*2):(pos*2+1)];
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
	int min_pos() const {
		return ipos[1];
	}
	T max() const {
		return ma[1];
	}
	int max_pos() const {
		return apos[1];
	}
};

const int INF  = 0x3FFFFFFF;
const int MAXN = 110;
const int MAXM = 1010;

mWinnerTree<int, MAXN*4> tree;
struct EDGE {int n, t, l;} edge[MAXM*2];
int n, m, dis[MAXN], head[MAXN], ans[MAXN];
bool used[MAXN];

void AddEdge(const int from, const int to, const int length) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	edge[CurEdge].l = length;
	head[from] = CurEdge;
	CurEdge ++;
}

int s_Dijkstra(const int start) {
	ans[start] = 1;
	memset(used, 0, sizeof(used));
	tree.clear();
	tree.edit(start, 0);
	for (int trees=0; trees<n; trees++) {
		int pos = tree.min_pos(), value = tree.min();
		dis[pos] = value;
		tree.edit(pos, INF);
		used[pos] = true;
		for (int i=head[pos], t, dis; i!=-1; i=edge[i].t) {
			t = edge[i].n;
			dis = edge[i].l;
			if (!used[t] && (!tree.exist(t) || value+dis<tree[t])) {
				tree.edit(t,value+dis);
				ans[t] = ans[pos];
			}
			else if (!used[t] && (!tree.exist(t) || value+dis==tree[t])) {
				ans[t] = (ans[t] + ans[pos]) % 1007;
			}
		}
	}
	return 0;
}

int main() {
	freopen("1631.in" , "r", stdin );
	freopen("1631.out", "w", stdout);
	for (int i=0; i<MAXN; i++)
		head[i] = -1;

	scanf("%d %d", &n, &m);
	tree.setLen(n);
	for (int i=0, from, to, tdis; i<m; i++) {
		scanf("%d %d %d", &from, &to, &tdis);
		AddEdge(from,  to , tdis);
		AddEdge( to , from, tdis);
	}

	s_Dijkstra(1);

	printf("%d\n", ans[n]);

	return 0;
}
