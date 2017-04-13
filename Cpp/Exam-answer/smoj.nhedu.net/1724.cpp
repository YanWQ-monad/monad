// 1724.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::max;
using std::min;

const int INF  = 0x6FFF7FFF;

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
		len = size;
		k = 1;
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
					else			   temp = pos * 2;
					mi[pos] = mi[temp];
					ma[pos] = ma[temp];
					ipos[pos] = ipos[temp];
					apos[pos] = apos[temp];
				}
				else {
					mi[pos] = ::min(mi[pos*2], mi[pos*2+1]);
					ma[pos] = ::max(ma[pos*2], ma[pos*2+1]);
					ipos[pos] = ipos[(mi[pos*2] <= mi[pos*2+1])? (pos*2):(pos*2+1)];
					apos[pos] = apos[(ma[pos*2] >= ma[pos*2+1])? (pos*2):(pos*2+1)];
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

const int MAXN = 310;
const int MAXM = 4010;
mWinnerTree<int, MAXN*4> tree;

struct EDGE {int n, t, l, f;} edge[MAXM*2];
int n, m, head[MAXN], dis[MAXN], te[MAXN][MAXN];
bool v[MAXN], ans[MAXM], curE[MAXM];

void AddEdge(const int from, const int to, const int length, const int number) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	edge[CurEdge].l = length;
	edge[CurEdge].f = number;
	head[from] = CurEdge;
	CurEdge ++;
}

void Init() {
	tree.clear();
	for (int i=0; i<=n; i++) {
		dis[i] = INF;
		v[i] = false;
		for (int j=0; j<=n; j++)
			te[i][j] = 0;
	}
	for (int i=1; i<=m; i++)
		curE[i] = false;
}

typedef enum { COVER, TOGET } AIE_FLA;
void AddImpEdge(const int u, const int v, const int num, const int flag) {
	//printf("\t%s %d <=%d=> %d\n", flag==COVER? "Cover":"Toget", u, num, v);
	curE[te[u][v]] = false;
	if (flag == COVER) {
		te[u][v] = num;
		curE[num] = true;
	}
}

int s_Dijkstra(const int start) {
	tree.edit(start, 0);
	for (int trees=0; trees<n; trees++) {
		int value = tree.min(), pos = tree.min_pos();
		tree.edit(pos, INF);
		dis[pos] = value;
		v[pos] = true;
		for (int i=head[pos], t, dis; i!=-1; i=edge[i].t) {
			t = edge[i].n;
			dis = edge[i].l;
			if (!v[t] && (!tree.exist(t) || value+dis<tree[t])) {
				tree.edit(t, value+dis);
				AddImpEdge(pos, t, edge[i].f, COVER);
			}
			else if (!v[t] && (!tree.exist(t) || value+dis==tree[t]))
				AddImpEdge(pos, t, edge[i].f, TOGET);
		}
	}
	return 0;
}

int main() {
	freopen("1724.in" , "r", stdin );
	freopen("1724.out", "w", stdout);

	for (int i=0; i<MAXN; i++)
		head[i] = -1;

	scanf("%d %d", &n, &m);
	tree.setLen(n);
	for (int i=1, u, v, w; i<=m; i++) {
		scanf("%d %d", &u, &v);
		w = 1;
		AddEdge(u, v, w, i);
		AddEdge(v, u, w, i);
	}

	for (int i=1; i<=n; i++) {
		Init();
		s_Dijkstra(i);
		for (int j=1; j<=m; j++)
			ans[j] = ans[j] || curE[j];
	}

	for (int i=1; i<=m; i++)
		if (ans[i])
			printf("%d\n", i);

	return 0;
}
