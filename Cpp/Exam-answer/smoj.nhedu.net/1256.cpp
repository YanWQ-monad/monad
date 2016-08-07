// 1256.cpp
#include <cstdio>

const int MAXN = 16;
int n,s[MAXN];
bool used[MAXN];
long long ans=0;
long long factorial(int n) {
	long long sum=1;
	for (int i=2;i<=n;i++)
		sum*=i;
	return sum;
}
void work() {
	for (int i=n-1;i>=0;i--) {
		int pos;
		for (pos=0;used[pos];pos++);
		for (int j=0;s[i]!=j;pos+=!used[j],j++);
		used[s[i]]=true;
		ans+=(pos-1)*factorial(i);
	}
}
int main() {
	freopen("1256.in","r",stdin);
	freopen("1256.out","w",stdout);
	scanf("%d",&n);
	for (int i=n-1;i>=0;i--)
		scanf("%d",&s[i]);
	work();
  #if !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
	printf("%I64d\n",ans+1);
  #else
	printf("%lld\n",ans+1);
  #endif
	return 0;
}
