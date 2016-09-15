// 1028.cpp
#include <cstdio>

int n,nq,p,ans;
short qa[50001][51],qaj[10][2];
bool ncu[50001];
int main() {
	freopen("1028.in","r",stdin);
	freopen("1028.out","w",stdout);
	scanf("%d %d %d",&n,&nq,&p);
	for (int i=0;i<n;i++)
		for (int j=0;j<nq;j++)
			scanf("%d",&qa[i][j]);
	for (int i=0;i<p;i++)
		scanf("%d %d",&qaj[i][0],&qaj[i][1]);
	for (int i=0;i<n;i++)
		for (int j=0;j<p;j++)
			if  (qa[i][qaj[j][0]-1]!=qaj[j][1]) {
				ncu[i]=true;
				break;
			}
	for (int i=0;i<n;i++)
		if  (!ncu[i])   ans++;
	printf("%d",ans);
	return 0;
}
