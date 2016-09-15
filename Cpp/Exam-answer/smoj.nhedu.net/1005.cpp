#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int n,ans;
map <int,int> a;
int main() {
	freopen("1005.in","r",stdin);
	freopen("1005.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n;i++) {
		int temp;
		scanf("%d",&temp);
		a[temp]++;
	}
	for	(int i=0;i<=1000000;i++)
		if	(a.count(i)) {
			ans += ceil((double)a[i]/(i+1))*(i+1);
		}
	printf("%d\n",ans);
	return 0;
}
