// d.cpp
#include <cstring>
#include <cstdio>
#include <queue>
using std::queue;

const int MAXN = 20;
int min=2147483647;
int used[1<<20];
const int fan[20]={786432,917504,458752,229376,114688,57344,28672,14336,7168,3584,1792,896,448,224,112,56,28,14,7,3};
void bfs(int temp) {
	queue<int>p;
	p.push(temp);
	while (!p.empty()) {
		temp=p.front();p.pop();
		for (int i=0;i<MAXN;i++) {
			int newbowl=temp^fan[i];
			if (newbowl==0) {printf("%d\n",used[temp]+1);return;}
			if (used[newbowl]) continue;
			used[newbowl]=used[temp]+1;
			p.push(newbowl);
		}
	}
	puts("-1");
}
int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int bowl=0;
	for (int i=0,temp;i<MAXN;i++) {
		scanf("%d",&temp);
		bowl=(bowl<<1)+(bool)temp;
	}
	used[bowl]=0;
	if (bowl==0) puts("0");
	else bfs(bowl);
	return 0;
}
