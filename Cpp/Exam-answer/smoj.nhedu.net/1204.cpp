// 1204.cpp
#include <algorithm>
#include <cstdio>
using std::abs;

int r,n,rose[20],lilie[20],ro,li,minn;
int main() {
	freopen("1204.in","r",stdin);
	freopen("1204.out","w",stdout);
	scanf("%d",&r);
	for	(int t=0;t<r;t++) {
		scanf("%d",&n);
		for	(int i=0;i<n;i++)
			scanf("%d",&rose[i]);
		for	(int i=0;i<n;i++)
			scanf("%d",&lilie[i]);
		minn=2147483647;
		for	(int i=0;i<(1<<n);i++) {
			ro=li=0;
			for	(int k=0;k<n;k++)
				if	(i&(1<<k)) {
					ro+=rose[k];
					li+=lilie[k];
				}
			if	(abs(ro-li)>1)	continue;
			for	(int k=1;k*k<=ro+li;k++) {
				if	((ro+li)%k!=0)	continue;
				if	((k%2==0 || ((ro+li)/k)%2==0) && abs(ro-li)==0 && abs((ro+li)/k-k)<minn) minn=abs((ro+li)/k-k);
				if	(k%2==1 && ((ro+li)/k)%2==1 && abs(ro-li)==1 && abs((ro+li)/k-k)<minn)   minn=abs((ro+li)/k-k);
			}
		}
		if	(minn==2147483647)	printf("-1\n");
		else	printf("%d\n",minn);
	}
	return 0;
}
