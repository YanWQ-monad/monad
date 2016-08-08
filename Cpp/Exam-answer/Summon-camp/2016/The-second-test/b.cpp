// b.cpp
#include <cstdio>
#include <ctime>
#define min(x,y) ((x)<(y)? (x):(y))

const int MAXN = 100010;
int n,diff,PowerTop,a[MAXN],left[MAXN],right[MAXN];

void InitLinkedList() {
	int last=0;
	for (int i=1;i<MAXN;i++) {
		if (!a[i]) continue;
		left[i]=last;
		right[last]=i;
		last=i;
		diff++;
	}
	PowerTop=last+1;
	right[last]=PowerTop;
	left[PowerTop]=last;
}
void LinkedRemove(int n) {
	diff--;
	left[right[n]]=left[n];
	right[left[n]]=right[n];
}
void EnhancedSimulation() {
	int deal;
	while (diff>3) {
		deal=min(a[right[0]],a[left[PowerTop]]);
		a[right[right[0]]]+=deal;
		a[left[left[PowerTop]]]+=deal;
		a[right[0]]-=deal;
		a[left[PowerTop]]-=deal;
		if (!a[right[0]]) LinkedRemove(right[0]);
		if (!a[left[PowerTop]]) LinkedRemove(left[PowerTop]);
	}
	bool toWho;
	for (toWho=false;diff>2;) {
		if (!toWho) {
			int minpower=right[0];
			a[minpower]--;
			a[right[minpower]]++;
			if (!a[minpower]) LinkedRemove(minpower);
			toWho=true;
		}
		else {
			int maxpower=left[PowerTop];
			a[maxpower]--;
			a[left[maxpower]]++;
			if (!a[maxpower]) LinkedRemove(maxpower);
			toWho=false;
		}
	}
	if (toWho) puts("Mirko");
	else puts("Slavko");

}
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,temp;i<n;i++) {
		scanf("%d",&temp);
		a[temp]++;
	}
	InitLinkedList();
	EnhancedSimulation();
	printf("%d %d\n",right[0],left[PowerTop]);
	return 0;
}
