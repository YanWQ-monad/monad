// 1250.cpp
#include <cstdio>
#include <string>
#include <map>
using std::string;
using std::map;
map<string,int>p;
int n;
char temp[25];
string stt;
int main() {
	freopen("1250.in","r",stdin);
	freopen("1250.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%s",temp);
		stt=temp;
		p[stt]++;
	}
	for (int i=0;i<n-1;i++) {
		scanf("%s",temp);
		stt=temp;
		if ((--p[stt])==0)
			p.erase(stt);
	}
	for (map<string,int>::iterator iter=p.begin();iter!=p.end();iter++)
		printf("%s",iter->first.c_str());
	return 0;
}
