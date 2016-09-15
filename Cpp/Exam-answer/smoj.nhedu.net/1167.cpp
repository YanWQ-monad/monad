// 1167.cpp
#include <cstdio>
int n,c,w[50001];
bool check(int m) {
	if  (m>n)   return false;
	int eat=0,full=0;
	for (int i=0;i<n;i++) {
		eat++;
		full+=w[i];
		if	(eat>=m) {
			full-=w[i-m];
			if	(full<=c)    return true;
		}
	}
	return false;
}
int find() {
	int l=0,r=n+1,mid;
	while   (l+1<r) {
		mid=(l+r)/2;
		if  (check(mid))    l=mid;
		else    r=mid;
	}
	return l;
}
int main() {
	freopen("1167.in","r",stdin);
	freopen("1167.out","w",stdout);
	scanf("%d %d",&n,&c);
	for (int i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("%d",find());
	return 0;
}
