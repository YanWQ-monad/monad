// a.cpp
#include <cstdio>
const int MAXN = 100010;
int n;
char s[MAXN];
int num[11];
int len() {
	bool zero=false;
	int sum=0,i;
	for (i=0;s[i]!=0;i++) {
		if (s[i]=='0') zero=true;
		sum += s[i]-'0';
		num[s[i]-'0']++;
	}
	if (zero && sum%3==0) return i;
	return 0;
}
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	gets(s);
	n=len();
	if (n==0) printf("-1");
	else
		for (int i=9;i>=0;i--)
			while (num[i])
				{printf("%d",i);num[i]--;}
	puts("");
	return 0;
}
