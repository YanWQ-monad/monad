// 1243.cpp
#include <cstdio>
int n,root,child[101][2];
bool HasFather[101];
void read() {
	freopen("1243.in","r",stdin);
	freopen("1243.out","w",stdout);
	scanf("%d",&n);
	int a,b;
	while (scanf("%d %d",&a,&b)!=EOF) {
		if (child[b][0]) child[b][1]=a;
		else child[b][0]=a;
		HasFather[a]=true;
	}
}
void work() {
	for (int i=n;i;i--) {
		if (!HasFather[i]) {root=i;continue;}
		if (child[i][0]>child[i][1] && child[i][1])
			child[i][0]^=child[i][1]^=child[i][0]^=child[i][1];
	}
}
void tree(int now) {
	if (child[now][0]) tree(child[now][0]);
	printf("%d ",now);
	if (child[now][1]) tree(child[now][1]);
}
void tree2(int now) {
	if (child[now][0]) tree2(child[now][0]);
	if (child[now][1]) tree2(child[now][1]);
	printf("%d ",now);
}
int main() {
	read();
	work();
	tree(root);
	printf("\n");
	tree2(root);
	return 0;
}
