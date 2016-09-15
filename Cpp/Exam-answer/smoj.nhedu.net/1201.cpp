// 1201.cpp
#include <utility>
#include <string>
#include <cstdio>
using std::string;
using std::pair;

pair<string,int>p[101];
char Temp[21];
int n,m,ans,o;
bool check(int k) {
	int same;
	string temp;
	for	(int i=0;i<m;i++) {
		same=0;
		temp=(p+i)->first;
		for	(int j=0;j<n;j++)
			if	(temp[j]=='1' && (k&(1<<(n-j-1)))>0)
				same++;
		if	(same!=(p+i)->second)	return false;
	}
	return true;
}
int main() {
	freopen("1201.in","r",stdin);
	freopen("1201.out","w",stdout);
	scanf("%d %d",&n,&m);
	for	(int i=0,temp;i<m;i++) {
		scanf("%s %d",Temp,&temp);
		(p+i)->first=Temp;
		(p+i)->second=temp;
	}
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
