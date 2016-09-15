#include <cstdio>
int a1,a2,b1,b2,ans=0;
int main() {
	freopen("1002.in","r",stdin);
	freopen("1002.out","w",stdout);
	scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
	ans+=(a2-a1+1);
	ans+=(b2-b1+1);
	if	(a1<=b1 && a2>=b2)
		ans-=(b2-b1+1);
	if	(a1>=b1 && a2<=b2)
		ans-=(a2-a1+1);
	if	(a1<=b1 && a2>=b1 && b2>=a2)
		ans-=(a2-b1+1);
	if	(a1>=b1 && a1<=b2 && b2<=a2)
		ans-=(b2-a1+1);
	printf("%d",ans);
	return 0;
}
