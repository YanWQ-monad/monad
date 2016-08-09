// 1265.cpp
#include <cstring>
#include <cstdio>

const int MAXN = 20;
const int prime[7]={2,3,5,7,11,13,17};
int r,a,b;
double f[MAXN][2];
void dp() {
	for (int i=1;i<=18;i++) {
		double ft[MAXN][2];
		memcpy(ft,f,sizeof(ft));
		for (int j=i;j;j--) {
			ft[j][0]+=f[j-1][0]*(double)(a)/100;
			ft[j][1]+=f[j-1][1]*(double)(b)/100;
		}
		for (int j=i;j;j--) {
			ft[j-1][0]-=f[j-1][0]*(double)(a)/100;
			ft[j-1][1]-=f[j-1][1]*(double)(b)/100;
		}
		memcpy(f,ft,sizeof(f));
	}
}
void printD(double n) {
	char temp[20];
	sprintf(temp,"%.16lf",n);
	int p;
	for (p=17;p>=0 && temp[p]=='0';p--);
	if (temp[p]=='.') p++;
	for (int i=0;i<=p;i++)
		printf("%c",temp[i]);
	puts("");
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
		//printf("%lf\n",ans1+ans2-ans1*ans2);
		printD(ans1+ans2-ans1*ans2);
	}
	
	return 0;
}
