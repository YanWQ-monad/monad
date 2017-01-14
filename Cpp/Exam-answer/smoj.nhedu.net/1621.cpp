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
		for (int i=0; i<MAX_LEN; i++)
			isNone[i] = true;
		for (int i=k; i<2*k; i++)
			ipos[i] = apos[i] = i - k + 1;
	}
	mWinnerTree(const int size = 0) : len(size), k(1){
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
	T operator[](const int pos) const {
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
int n, p, c, cow[MAXN], dis[MAXP], ans=INF, head[MAXP];
bool used[MAXP];

void AddEdge(const int from, const int to, const int length) {
	static int CurEdge = 0;
	edge[CurEdge].t = head[from];
	edge[CurEdge].n = to;
	edge[CurEdge].l = length;
	head[from] = CurEdge;
	CurEdge ++;
}

int Dijkstra(const int start) {
	memset(used, 0, sizeof(used));
	tree.clear();
	tree.edit(start, 0);
	for (int trees=0; trees<p; trees++) {
		int vaule = tree.min(), pos = tree.min_pos();
		tree.edit(pos, INF);
		dis[pos] = vaule;
		used[pos] = true;
		for (int i=head[pos], to, dis; i!=-1; i=edge[i].t) {
			to = edge[i].n;
			dis = edge[i].l;
			if (!used[to] && (!tree.exist(to) || vaule+dis<tree[to]))
				tree.edit(to, vaule+dis);
		}
	}
	return 0;
}

int main() {
	freopen("Temp.in" , "r", stdin );
	freopen("Temp.out", "w", stdout);
	for (int i=0; i<MAXP; i++)
		head[i] = -1;

	scanf("%d %d %d", &n, &p, &c);
	tree.setLen(p);
	for (int i=1; i<=n; i++)
		scanf("%d", &cow[i]);
	for (int i=0, from, to, tdis; i<c; i++) {
		scanf("%d %d %d", &from, &to, &tdis);
		AddEdge(from,  to , tdis);
		AddEdge( to , from, tdis);
	}

	for (int i=1, j, tot; i<=p; i++) {
		Dijkstra(i);
		for (j=1, tot=0; j<=n; j++)
			tot += dis[cow[j]];
		ans = min(ans, tot);
	}

	printf("%d\n", ans);

	return 0;
}

