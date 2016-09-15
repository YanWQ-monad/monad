// 1110.cpp
#include <cstdio>
int n,m=-2147483647;
int main() {
	freopen("1110.in","r",stdin);
	freopen("1110.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,temp;scanf("%d",&temp),m=temp>m? temp:m,i<n-1;i++);
	printf("%d\n",m);
	return 0;
}
