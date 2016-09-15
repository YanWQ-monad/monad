// 1111.cpp
#include <cstdio>
int n,m=-10000000,o=-10000000;
int main() {
	freopen("1111.in","r",stdin);
	freopen("1111.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,temp;i<n;i++) {
		scanf("%d",&temp);
		temp>m? o=m,m=temp:(temp>o? o=temp:o=o);
	}
	printf("%d\n",o);
	return 0;
}
