// 1025.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,c[51],qz[51],w[2501],ans,qzed;
bool h[2501];
int comp(const int a,const int b) {
	return a>b;
}
int qzok() {
	for (int i=0;i<m;i++)
		if  (qz[i]<n-1)    return false;
	return true;
}
int main() {
	freopen("1025.in","r",stdin);
	freopen("1025.out","w",stdout);
	scanf("%d %d",&m,&n);
	for (int i=0;i<m;i++)
		scanf("%d",&c[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&w[i]);
	sort(c,c+m,comp);
	sort(w,w+n,comp);
	if  (c[0]<w[0])
		printf("-1\n");
	else {
		while   (!qzok()) {
			if	(qzed<n)	ans++;
			for (int i=0;i<m;i++) {
				while   (qz[i]<=n &&(h[qz[i]] || w[qz[i]]>c[i]))    qz[i]++;
				if	(qz[i]<n)	{
					h[qz[i]]=true;
					qzed++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
