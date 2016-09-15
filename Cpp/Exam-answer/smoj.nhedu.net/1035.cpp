// 1035.cpp
#include <algorithm>
#include <cstdio>
using std::min;

int n,r,ans=1,sj[2001][2001];
int main() {
	freopen("1035.in","r",stdin);
	freopen("1035.out","w",stdout);
	scanf("%d %d",&n,&r);
	n=n+r;
	r=min(n-r,r);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
			if  (j==0 || j==i)  sj[i][j]=1;
			else	sj[i][j]=(sj[i-1][j-1]+sj[i-1][j])%10007;
	printf("%d",sj[n][r]);
    return 0;
}
