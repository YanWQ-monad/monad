// 1065.cpp
#include <algorithm>
#include <cstdio>
using std::min;

int n,m,mod;
int main() {
	freopen("1065.in","r",stdin);
	freopen("1065.out","w",stdout);
	scanf("%d %d %d",&n,&m,&mod);
	printf("%d",min(n%mod,m%mod));
	return 0;
}
