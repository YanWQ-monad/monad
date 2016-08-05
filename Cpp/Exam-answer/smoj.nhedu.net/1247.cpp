#include <cstdio>

const int MAXN = 100010;
long long a[MAXN],temp[MAXN],sum=0;
int n;

template<typename T>
void mergesort(T *begin,T *end,T *Temp) {
	if (begin>=end) return;
	int size=end-begin,mid=size>>1;
	mergesort(begin,&begin[mid],Temp);
	mergesort(&begin[mid+1],end,&Temp[mid+1]);
	int l=0,r=mid+1,now=0,rt=0;
	while (l<=mid && r<=size) {
		if (begin[l]<=begin[r])	{
			Temp[now++]=begin[l++];
			sum+=rt;
		}
		else {
			Temp[now++]=begin[r++];
			rt++;
		}
	}
	while (l<=mid)            {sum+=rt;Temp[now++]=begin[l++];}
	while (r<=size)           Temp[now++]=begin[r++];
	for (int i=0;i<=size;i++) begin[i]=Temp[i];
}

int main() {
	freopen("1247.in","r",stdin);
	freopen("1247.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	mergesort(a,a+n-1,temp);
	printf("%lld\n",sum);
	return 0;
}
