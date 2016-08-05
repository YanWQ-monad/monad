// 1248.cpp
#include <cstdio>

const int MAXN = 100;
int sum=0,n,s[MAXN];
long long k;
bool used[MAXN];

void print() {
	for (int i=0;i<n;i++)
		printf("%d ",s[i]);
	printf("\n");
}
long long factorial(int n) {
	long long sum=1;
	for (int i=2;i<=n;i++)
		sum*=i;
	return sum;
}
void dfs(int x) {
	if (x==1) {
		for (int i=0;used[i];s[n-x]=++i);
		print();
		return;
	}
	int mod=(k/factorial(x-1))%x,i;
	//printf("mod=(%d/%d)%%%d=%d\n",k,countsum(x-1),x,mod);
	for (i=1;used[i];i++);
	for (int j=0;j<mod;j+=!used[i],i++);
	for (;used[i];i++);
	used[s[n-x]=i]=true;
	dfs(x-1);
}

int main() {
	freopen("1248.in","r",stdin);
	freopen("1248.out","w",stdout);
	#if !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
	scanf("%d %I64d",&n,&k);
	#else
	scanf("%d %lld",&n,&k);
	#endif
	k--;
	used[0]=true;
	dfs(n);
	return 0;
}
