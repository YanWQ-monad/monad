// 1265.cpp
#include <cstring>
#include <cstdio>

const int MAXN = 20;
const int prime[7]={2,3,5,7,11,13,17};
int r,a,b;
double f[MAXN][2];
void dp() {
	for (int i=1;i<=18;i++)
		for (int j=i;j;j--) {
			f[j][0]+=f[j-1][0]*(double)(a)/100;
			f[j-1][0]-=f[j-1][0]*(double)(a)/100;
			f[j][1]+=f[j-1][1]*(double)(b)/100;
			f[j-1][1]-=f[j-1][1]*(double)(b)/100;
		}
}
int main() {
	freopen("1265.in","r",stdin);
	freopen("1265.out","w",stdout);
	scanf("%d",&r);
	for (int rt=0;rt<r;rt++) {
		double ans1=0,ans2=0;
		scanf("%d %d",&a,&b);
		memset(f,0,sizeof(f));
		f[0][0]=f[0][1]=1;
		dp();
		for (int i=0;i<7;i++) {
			ans1+=f[prime[i]][0];
			ans2+=f[prime[i]][1];
		}
		printf("%.16lf\n",ans1+ans2-ans1*ans2);
	}
	return 0;
}
