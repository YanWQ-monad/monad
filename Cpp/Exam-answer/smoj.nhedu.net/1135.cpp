// 1135.cpp
#include <cstdio>

int n,d[50],m;
bool f[1002][1002];
int main() {
	freopen("1135.in","r",stdin);
	freopen("1135.out","w",stdout);
	scanf("%d",&n);
	for (int i=1,temp;i<=n;i++) {
		scanf("%d",&temp);
		d[i]=temp;
		f[i][temp]=true;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=1000;j++) {
			if  (f[i-1][j] || (j-d[i]>0 && f[i-1][j-d[i]]))
				f[i][j]=true;
		}
	for (int i=1;i<1001;i++)
		if  (f[n][i]==false)
			printf("%d ",i);
	return 0;
}
