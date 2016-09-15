// 1026.cpp
#include <iostream>
#include <cstdio>
#include <string>
using std::string;

int n,ans;
char st[51];
string s[1001];
int main() {
	freopen("1026.in","r",stdin);
	freopen("1026.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n;i++) {
		scanf("%s",st);
		string temp=st;
		ans=0;
		for	(unsigned j=0;j<temp.size();j++)
			for	(unsigned k=j;k<temp.size();k++) {
				string zic=temp.substr(j,k-j+1);
				for	(unsigned l=k+1;l<=temp.size();l++)
					if	(temp.find(zic,l)==l)
						ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
