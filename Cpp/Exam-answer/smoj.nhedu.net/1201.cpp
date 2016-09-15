// 1201.cpp
#include <utility>
#include <cstring>
#include <cstdio>
using std::pair;

pair<int,int>p[101];
char Temp[21];
int n,m,ans,o,f[(int)(1<<20)+1];
bool check(int k) {
	int same;
	for	(int i=0;i<m;i++)
		if	((f[(k&((p+i)->first))])!=(p+i)->second)	return false;
	return true;
}
int main() {
	freopen("1201.in","r",stdin);
	freopen("1201.out","w",stdout);
	scanf("%d %d",&n,&m);
	for	(int i=0,b,temp;i<m;i++) {
		scanf("%s %d",Temp,&b);
		temp=strlen(Temp);
		for	(int j=0;j<temp;j++)
			(p+i)->first+=(Temp[j]-'0')<<(temp-j-1);
		(p+i)->second=b;
	}
	for	(int i=0;i<(1<<n);i++)
		for	(int j=0;j<n;j++)
			if	((i&(1<<j)))
				f[i]++;
	for	(int i=0;i<(1<<n);i++) {
		if	(check(i))	{ans++;o=i;}
		if	(ans>1)	{printf("NOT UNIQUE\n");return 0;}
	}
	if	(!ans)	{printf("IMPOSSIBLE\n");return 0;}
	for	(int i=n-1;i>=0;i--)
		printf("%d",bool(o&(1<<i)));
	printf("\n");
	return 0;
}
