// 1066.cpp
#include <cstdio>

int n,m,o;
int main() {
	freopen("1066.in","r",stdin);
	freopen("1066.out","w",stdout);
	scanf("%d %d %d",&n,&m,&o);
	printf("%s\n",n+m>o && m+o>n && n+o>m ? "yes":"no");
	return 0;
}
