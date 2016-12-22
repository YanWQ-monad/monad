#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;
using std::max;

#define clean(arr, con, len) for (int i=0; i<len ; i++) arr[i] = con;
#define iftdo(con, tdo, len) for (int i=1; i<=len; i++) if(con) {tdo;}
const int MAXN = 5010;
const int MAXM = 50010;
typedef enum {DO, DOING, DID} status;
struct EDGE {int f, t;} edgs[MAXM];
bool hadin[MAXN], hadout[MAXN];
vector<int> edge[MAXN], iedge[MAXN];
int n, m, ans=-1;

char s[MAXN];
int in[MAXN], out[MAXN];
void dp() {
	for (int i=1; i<=n; i++) {
		for (int j=0; j<(int)iedge[i].size(); j++) {
			in[i] += in[iedge[i][j]];
		}
	}
	for (int i=n; i; i--) {
		for (int j=0; j<(int)edge[i].size(); j++) {
			out[i] += out[edge[i][j]];
		}
	}
}

int main() {
	freopen("1529.in" , "r", stdin );
	freopen("1529.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i=0, a, b; i<m; i++) {
		scanf("%d %d", &a, &b);
		edge [a].push_back(b);
		iedge[b].push_back(a);
		hadin[b]  = true;
		hadout[a] = true;
		edgs[i].f = a;
		edgs[i].t = b;
	}
	
	iftdo(!hadin[i] , in[i]=1 , n);
	iftdo(!hadout[i], out[i]=1, n);
	
	dp();
	
	for (int i=0; i<m; i++) {
		ans = max(ans, in[edgs[i].f] * out[edgs[i].t]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}
