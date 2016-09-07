// 1303.cpp
#include <algorithm>
#include <cstdio>
using std::max;

const int MOD = 1000000007;
int n,k,a[2010],C[2010][2010];
void InitTriangle(int Deep) {
	for (int i=0;i<=Deep;i++)
		for (int j=0;j<=i;j++)
			C[i][j] = j==0 || j==i? 1:(C[i-1][j]+C[i-1][j-1])%MOD;
}
int power(int n, int m) {
	int sum = 1;
	for (int i=0;i<m;i++)
		sum = (int)((long long)sum * n % MOD);
	return sum;
}
int main() {
	freopen("1303.in","r",stdin);
	freopen("1303.out","w",stdout);
	scanf("%d %d",&n,&k);
	//for (int i=0;i<n;i++)
	//	scanf("%d",&a[i]);
	InitTriangle(max(n,k)+1);
	printf("%d\n",(int)((long long)power(2, n - k) * C[n][k] % MOD));
	return 0;
}
