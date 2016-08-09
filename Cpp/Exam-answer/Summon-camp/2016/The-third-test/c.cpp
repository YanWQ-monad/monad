// c.cpp
#include <cstring>
#include <cstdio>

const int MAXN = 60;
int r,n,m,money[11];
int f[MAXN][15];
int CompareNumber(int lhs[],int rhs[]) {
	int suml=0,sumr=0;
	bool zero1=false,zero2=false;
	for (int i=n-1;i>=0;i--) {
		zero1=zero1 || (lhs[i]>0 && i!=0);
		zero2=zero2 || (rhs[i]>0 && i!=0);
		suml+=lhs[i];
		sumr+=rhs[i];
	}
	if (zero1!=zero2) return zero1>zero2;
	if (zero1 && zero2 && suml!=sumr) return suml>sumr;
	for (int i=n-1;i>=0;i--)
		if (lhs[i]!=rhs[i])
			return lhs[i]>rhs[i];
	return 0;
}
void AddNumber(int ret[],const int g[],int add) {
	for (int i=0;i<n;i++)
		ret[i]=g[i];
	ret[add]++;
}
void dp() {
	for (int i=1;i<=m;i++)
		for (int j=0;j<n;j++) {
			int LessMoney=i-money[j+1];
			if (LessMoney<0) continue;
			int temp[15];
			for (int k=0;k<=LessMoney;k++) {
				memset(temp,0,sizeof(temp));
				AddNumber(temp,f[k],j);
				if (CompareNumber(temp,f[i])==1)
					memcpy(f[i],temp,sizeof(temp));
			}
		}
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&r);
	for (int rt=0;rt<r;rt++) {
		memset(f,0,sizeof(f));
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&money[i]);
		dp();
		for (int i=n-1,NoZero=0;i>=0;i--)
			for (int j=0;j<f[m][i];j++) {
				if (i>0) NoZero=1;
				if (i==0 && !NoZero) {printf("%d",i);break;}
				else printf("%d",i);
			}
		puts("");
	}
	return 0;
}
