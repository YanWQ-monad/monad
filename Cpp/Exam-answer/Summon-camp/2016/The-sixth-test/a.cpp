// a.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::min;

int r,n,cost[21][3];
void dp() {
	for (int i=1;i<=n;i++) {
		cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
		cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
		cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
	}
}
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&r);
	for (int rt=0;rt<r;rt++) {
		memset(cost,0,sizeof(cost));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);
		dp();
		printf("%d\n",min(cost[n][0],min(cost[n][1],cost[n][2])));
	}
	return 0;
}
