// 1283.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::min;
using std::max;
long long GetLongLong() {
	long long temp;
  #if !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
	scanf("%I64d",&temp);
  #else
	scanf("%lld",&temp);
  #endif
	return temp;
}
void PrintLongLong(long long n) {
	if (n<1000000000) printf("%d",(int)n);
	else printf("%d%09d",(int)(n/1000000000),(int)(n%1000000000));
}

int n,x[15];
long long a,b,ans=0;
long long in(long long start,long long end,long long div) {
	long long MinPos=(start-1)/div+1;
	long long MaxPos=end/div;
	return MaxPos-MinPos+1;
}
void dbdbfs(int next,int cnt,long long sum) {
	long long Temp,gs;
	for (int i=next;i<n;i++) {
		Temp = sum*x[i];
		if (Temp>b || Temp<=0) continue;
		gs=in(a,b,Temp);
		if (cnt%2) ans += gs;
		else ans -= gs;
		dbdbfs(i+1,cnt+1,Temp);
	}
}
int main() {
	freopen("1283.in","r",stdin);
	freopen("1283.out","w",stdout);
	scanf("%d",&n);
	a=GetLongLong();
	b=GetLongLong();
	for (int i=0;i<n;i++)
		scanf("%d",&x[i]);
	dbdbfs(0,1,1);
	PrintLongLong(ans);
	putchar('\n');
	return 0;
}
