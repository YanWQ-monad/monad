// 1023.cpp
#include <cstdio>
#include <algorithm>
using std::sort;

int n,d[53],jlA,jlB;
int comp(const int a,const int b) {
	return a>b;
}
int main() {
	freopen("1023.in","r",stdin);
	freopen("1023.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&d[i]);
	sort(d,d+n,comp);
	for (int i=0;i<=n;i+=2) {
		jlA+=d[i];
		jlB+=d[i+1];
	}
	printf("%d\n",jlA-jlB);
	return 0;
}
