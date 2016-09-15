// 1222.cpp
#include <algorithm>
#include <cstdio>
using std::sort;
int r,n,k,l;
struct DICK {int x,p;}bird[51];
int BirdSort(DICK lhs,DICK rhs) {
	return lhs.x<rhs.x;
}
int main() {
	freopen("1222.in","r",stdin);
	freopen("1222.out","w",stdout);
	scanf("%d",&r);
	for	(int rt=0;rt<r;rt++) {
		scanf("%d %d",&n,&k);
		for	(int i=0;i<n;i++)
			scanf("%d",&bird[i].x);
		for	(int i=0;i<n;i++)
			scanf("%d",&bird[i].p);
		sort(bird,bird+n,BirdSort);
		l=bird[0].x-k;
		try {
			for	(int i=0;i<n;i++) {
				if	(bird[i].x-k>l)	l=bird[i].x-k;
				//printf("l=%d (%d,%d); %d and %d\n",l,bird[i].x,bird[i].p,bird[i].p+l-1,bird[i].x+k);
				if	(bird[i].p+l-1>bird[i].x+k)	{printf("Impossible\n");throw 0;}
				l+=bird[i].p;
			}
			printf("Possible\n");
		}
		catch(int e) {}
	}
	return 0;
}
