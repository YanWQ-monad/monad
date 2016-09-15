#include <cstdio>
int s,t,ans;
bool phone[11]={0,1,1,0,0,1,0,1,0,0,1};
int main() {
	freopen("1004.in","r",stdin);
	freopen("1004.out","w",stdout);
    scanf("%*d %d %d",&s,&t);
    for	(int i=(s-1)%11+1;i<=11 && s<=t;i++,s++)
    	if	(phone[i-1]==true)
    		ans++;
    for	(int i=(t-1)%11+1;i>0 && t>=s;i--,t--)
    	if	(phone[i-1]==true)
    		ans++;
    if	(s<t)
    	ans=ans+(t-s+1)/11*5;
    printf("%d\n",ans);
    return 0;
}
