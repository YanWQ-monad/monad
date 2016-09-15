// 1058.cpp
#include <cstdio>
#include <string>
using std::string;

string s;
char st[20];
bool hui(const string &s) {
	int l=0,r=s.size()-1;
	while	(l<r)
		if	(s[l++]!=s[r--])
			return false;	
	return true;
}
int main() {
	freopen("1058.in","r",stdin);
	freopen("1058.out","w",stdout);	
	scanf("%s",st);
	s=st;
	printf("%s",hui(s)? "1":"0");
	return 0;
}
