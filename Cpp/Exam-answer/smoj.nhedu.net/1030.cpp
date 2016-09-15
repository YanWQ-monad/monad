// 1030.cpp
#include <cstdio>

int s,t,st,tt,ans=0;
int main() {
	freopen("1030.in","r",stdin);
	freopen("1030.out","w",stdout);
	scanf("%d %d",&s,&t);
	st=s/1000000;tt=t/1000000;
	for (int i=st,temp;i<=tt;i++) {
		temp=i*1001001;
		if  (temp>=s && temp<=t) {
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
