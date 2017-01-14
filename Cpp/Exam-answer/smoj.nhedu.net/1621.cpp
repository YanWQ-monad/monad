// 1621.cpp
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
	//	for (int i=0; i<MAX_LEN; i++)
	//		isNone[i] = true;
		for (int i=k; i<2*k; i++)
			ipos[i] = apos[i] = i - k + 1;
	}
	mWinnerTree(const int size = 0) : len(size) , k(1){
		for (int i=0; i<MAX_LEN; i++)
			isNone[i] = true;
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

const int INF  = 0x3FFFFFFF;
const int MAXP = 810;
const int MAXN = 510;
const int MAXC = 3000;
mWinnerTree<int, MAXP*4> tree;

struct EDGE {int n, t, l;} edge[MAXC];
int n, p, c, cow[MAXN], dis[MAXP], ans=INF, cowin[MAXP], tot, head[MAXP];
bool used[MAXP];

void AddEdge(const int from, const int to, const int length) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	edge[CurEdge].l = length;
	head[from] = CurEdge;
	CurEdge ++;
}

int Dijkstra(const int from) {
	tree.edit(from, 0);
	for (int trees=0; trees<p; trees++) {
		int l = tree.min(), pos = tree.min_pos();
		tree.edit(pos, INF);
		dis[pos] = l;
		tot += dis[pos] * cowin[pos];
		used[pos] = true;
		for (int i=head[pos]; i!=-1; i=edge[i].t)
			if (!used[edge[i].n] && (!tree.exist(edge[i].n) || l+edge[i].l<tree[edge[i].n]))
				tree.edit(edge[i].n, l+edge[i].l);
	}
	return 0;
}

int main() {
	freopen("1621.in" , "r", stdin );
	freopen("1621.out", "w", stdout);
	for (int i=0; i<MAXP; i++)
		head[i] = -1;
	scanf("%d %d %d", &n, &p, &c);
	tree.setLen(p);
	for (int i=1; i<=n; i++) {
		scanf("%d", &cow[i]);
		cowin[cow[i]] ++;
	}
	for (int i=0, from, to, tdis; i<c; i++) {
		scanf("%d %d %d", &from, &to, &tdis);
		AddEdge(from,  to , tdis);
		AddEdge( to , from, tdis);
	}

	for (int i=1; i<=p; i++) {
		tot = 0;
		memset(used, 0, sizeof(used));
		tree.clear();
		Dijkstra(i);
		ans = min(ans, tot);
	}

	printf("%d\n", ans);

	return 0;
}
