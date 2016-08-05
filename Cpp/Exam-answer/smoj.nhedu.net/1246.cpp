// 1246.cpp
#include <cstdio>

template<typename T>
void mergesort(T *begin,T *end,T *Temp) {
	if (begin>=end) return;
	int size=end-begin,mid=size>>1;
	mergesort(begin,&begin[mid],Temp);
	mergesort(&begin[mid+1],end,&Temp[mid+1]);
	int l=0,r=mid+1,now=0;
	while (l<=mid && r<=size) Temp[now++]=begin[l]<begin[r]? begin[l++]:begin[r++];
	while (l<=mid)            Temp[now++]=begin[l++];
	while (r<=size)           Temp[now++]=begin[r++];
	for (int i=0;i<=size;i++) begin[i]=Temp[i];
}

const int MAXN = 10000000;
int n,a[MAXN],temp[MAXN];
int main() {
	freopen("1246.in","r",stdin);
	freopen("1246.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,a+n-1,temp);
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
