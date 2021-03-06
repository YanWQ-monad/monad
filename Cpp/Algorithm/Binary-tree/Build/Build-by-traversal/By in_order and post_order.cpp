#include <cstring>
#include <cstdio>

struct TREE {
	int data;
	TREE *left,*right;
	TREE():data(0),left(NULL),right(NULL) {}
	~TREE() {if (left) delete(left);if (right) delete(right);}
};
const int MAXN = 100;
int n,In[MAXN],Post[MAXN];
TREE *root;
void read() {
	int i,temp;
	for (i=0;scanf("%d",&temp)!=EOF;i++) {
		if (i>=MAXN) Post[i-MAXN]=temp;
		else In[i]=temp;
	}
	if (i>MAXN) memmove(Post,Post+MAXN-i/2,sizeof(int)+i-MAXN);
	memmove(Post,In+i/2,sizeof(int)+MAXN-i/2);
	n=i/2;
}

TREE* build(int Ib,int Ie,int Pb,int Pe) {
	if (Ib>Ie || Pb>Pe) return NULL;
	TREE *node=new TREE;
	int root=Post[Pe],p=Ib;
	node->data=root;
	while (In[p]!=root) p++;
	int cur=p-Ib;
	node->left  = build(Ib,p-1,Pb,Pb+cur-1);
	node->right = build(p+1,Ie,Pb+cur,Pe-1);
	return node;
}

void PreOrder(TREE *now) {
	printf("%d ",now->data);
	if (now->left)  PreOrder(now->left);
	if (now->right) PreOrder(now->right);
}

int main() {
	read();
	root=build(0,n-1,0,n-1);
	PreOrder(root);
	return 0;
}
