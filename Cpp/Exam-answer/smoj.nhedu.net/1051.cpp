// 1051.cpp
#include <cstdio>
#include <string>
using std::string;

char st[100];
string s;
int main() {
	freopen("1051.in","r",stdin);
	freopen("1051.out","w",stdout);
	scanf("%s",st);
	s=st;
	for	(unsigned i=0;i<s.size();i++) {
		for	(unsigned j=0;j<s.size()-i;j++)
			printf("%c",st[j]);
		printf("\n");
	}
	return 0;
}
