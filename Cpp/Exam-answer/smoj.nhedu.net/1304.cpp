// 1304.cpp
#include <cstdio>

const int MOD = 1000000007;
int m,n,C[2010][2010];
void InitC(int deep) {
	for (int i=0;i<=deep;i++)
		for (int j=0;j<=i && j<5;j++)
			C[i][j] = (j==0 || j==i)? 1:(C[i-1][j] + C[i-1][j-1]) % MOD;
}
int main() {
	freopen("1304.in", "r", stdin);
	freopen("1304.out", "w", stdout);
	scanf("%d %d", &m, &n);
	InitC(m + 1);
	printf("%d\n", ((C[m-n][3] + (m-n>0? C[n][2]*(m-n):0))% MOD + (m-n>=2? C[m-n][2]*n:0))% MOD);
	return 0;
}
