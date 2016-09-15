#include <cstdio>
#include <algorithm>
using std::sort;

int data[100005],n,temp,ans;
int main() {
	freopen("1003.in","r",stdin);
	freopen("1003.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	sort(data+1,data+n+1);
	data[0]=data[1];
	for (int i=1;i<=n;i++) {
		if (data[i]==data[i-1] && data[i]!=0)
			temp++;
		else
			temp=1;
		if (temp>=4) {
			temp=0;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
