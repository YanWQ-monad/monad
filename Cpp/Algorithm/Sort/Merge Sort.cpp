// Merge Sort.cpp
// The worst time complexity:   O(n log n)
// The best time complexity:    O(n)
// The average time complexity: O(n log n)
// The worst space complexity:  O(n)

#include <cstdio>

template<typename T> bool default_compare(T lhs,T rhs) {
	return lhs<=rhs;
}
template<typename T>
void mergesort(T *begin,T *end,T *Temp,bool(*mscomp)(T,T)=&default_compare) {
	if (begin>=end) return;
	int size=end-begin,mid=size>>1;
	mergesort(begin,&begin[mid],Temp);
	mergesort(&begin[mid+1],end,&Temp[mid+1]);
	int l=0,r=mid+1,now=0;
	while (l<=mid && r<=size)   Temp[now++]=mscomp(begin[l],begin[r])? begin[l++]:begin[r++];
	while (l<=mid)              Temp[now++]=begin[l++];
	while (r<=size)             Temp[now++]=begin[r++];
	for   (int i=0;i<=size;i++) begin[i]=Temp[i];
}

const int MAXN = 100;
int n,a[MAXN],temp[MAXN];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,a+n-1,temp);
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
