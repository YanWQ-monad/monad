// b.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::min;
using std::max;

int r,n,b[3],f[63][63][63];
void dp() {
	for (int i=0;i<=b[0];i++)
		for (int j=0;j<=b[1];j++)
			for (int k=0;k<=b[2];k++) {
				if (!i && !j && !k) {f[i][j][k]=0;continue;}
				f[i][j][k]=0x3FFFFFFF;
				f[i][j][k]=min(f[i][j][k],f[max(0,i-1)][max(0,j-3)][max(0,k-9)]+1);
				f[i][j][k]=min(f[i][j][k],f[max(0,i-1)][max(0,j-9)][max(0,k-3)]+1);
				f[i][j][k]=min(f[i][j][k],f[max(0,i-3)][max(0,j-1)][max(0,k-9)]+1);
				f[i][j][k]=min(f[i][j][k],f[max(0,i-3)][max(0,j-9)][max(0,k-1)]+1);
				f[i][j][k]=min(f[i][j][k],f[max(0,i-9)][max(0,j-1)][max(0,k-3)]+1);
				f[i][j][k]=min(f[i][j][k],f[max(0,i-9)][max(0,j-3)][max(0,k-1)]+1);
			}
}
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&r);
	for (int rt=0;rt<r;rt++) {
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		b[0]=b[1]=b[2]=0;
		for (int i=0;i<n;i++)
			scanf("%d",&b[i]);
		if (n==1) {printf("%d\n",(b[0]-1)/9+1);continue;}
		dp();
		printf("%d\n",f[b[0]][b[1]][b[2]]);
	}
	return 0;
}
