// 1279.cpp
#include <cstring>
#include <cstdio>

int r,n,b,h,c[51];
bool can[51][1024];
void read() {
	scanf("%d %d %d",&n,&b,&h);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	memset(can,0,sizeof(can));
	can[0][b]=true;
}
void work() {
	for (int i=1;i<=n;i++)
		for (int j=0;j<=h;j++) {
			if      (j-c[i]>=0 && can[i-1][j-c[i]]) can[i][j]=true;
			else if (j+c[i]<=h && can[i-1][j+c[i]]) can[i][j]=true;
		}
}
void print() {
	for (int i=h;i>=0;i--)
		if (can[n][i]) {
			printf("%d\n",i);
			return;
		}
	puts("-1");
}
int main() {
	freopen("1279.in","r",stdin);
	freopen("1279.out","w",stdout);
	scanf("%d",&r);
	for (int rt=0;rt<r;rt++) {
		read();
		work();
		print();
	}
	return 0;
}
