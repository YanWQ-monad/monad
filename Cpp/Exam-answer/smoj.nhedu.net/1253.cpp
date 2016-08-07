// 1253.cpp
#include <cstdio>
#include <queue>
using std::queue;
#define max(x,y) ((x)>(y)? (x):(y))
#define abs(x) ((x)<0? (-(x)):(x))
const int MAXN = 1010;
char out[MAXN][MAXN];
int high[MAXN],n,maxh=0,minw=MAXN,maxw=0;
int C() {
	int sum=0;
	for (int i=minw;i<=maxw+1;i++) {
		if (!high[i] && high[i-1]) sum+=abs(high[i-1]-high[i]);
		if (!high[i]) continue;
		sum++;
		if (high[i-1]!=high[i]) sum+=abs(high[i-1]-high[i]);
	}
	return sum;
}
void print() {
	for (int i=maxh;i>0;i--) {
		for (int j=minw;j<=maxw;j++) {
			if (i==high[j]) putchar('#');
			else if (i>high[j]) putchar('.');
			else if (i<high[j] && i>=high[j-1]) putchar('#');
			else if (i<high[j] && i>=high[j+1]) putchar('#');
			else putchar('.');
		}
		putchar('\n');
	}
	for (int i=minw;i<=maxw;i++)
		putchar('*');
}
int main() {
	freopen("1253.in","r",stdin);
	freopen("1253.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,li,ri,hi;i<n;i++) {
		scanf("%d %d %d",&li,&ri,&hi);
		li++;ri++;
		//draw(li,0,ri-1,hi);
		maxh=hi>maxh? hi:maxh;
		maxw=ri-1>maxw? ri-1:maxw;
		minw=li<minw? li:minw;
		for (int i=li;i<ri;i++) {
			high[i]=max(high[i],hi);
		}
	}
	for (int i=minw;i<=maxw;i++)
		out[i][0]='*';
	printf("%d\n",C());
	print();
	return 0;
}
