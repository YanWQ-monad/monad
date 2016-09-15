// 1029.cpp
#include <cstdio>
#include <algorithm>
using std::sort;

int n,m,s,t,ans,at,bt,k,y,a[101],b[101],c[201];
int main() {
	freopen("1029.in","r",stdin);
	freopen("1029.out","w",stdout);
	k = ans = at = bt = y = 0;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	if (t>n || t>m) {
		puts("-1");
		return 0;
	}
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<m;i++)
		scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	s = s*60;
	for (int i=0;i<t;i++) {
		at += a[i];
		bt += b[i];
	}
	s -= at+bt;
	if (s < 0) {
		puts("-1");
		return 0;
	}
	for (int i=t;i<n;i++)
		c[k++] = a[i];
	for (int i=t;i<m;i++)
		c[k++] = b[i];
	y = n+m-2*t;
	sort(c,c+y);
	for (int i=0;i<y && s>=c[i];i++) {
		ans++;
		s -= c[i];
	}
	printf("%d\n",ans+t*2);
    return 0;
}
