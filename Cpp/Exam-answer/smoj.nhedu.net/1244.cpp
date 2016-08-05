#include <cstring>
#include <cstdio>

struct TREE {
	int data;
	TREE *left,*right;
	TREE():data(0),left(NULL),right(NULL) {}
	~TREE() {if (left) delete(left);if (right) delete(right);}
};
const int MAXN = 1000;
int n,Pre[MAXN],In[MAXN];
TREE *root;
void read() {
	scanf("%*d");
	int i,temp;
	for (i=0;scanf("%d",&temp)!=EOF;i++) {
		if (i>=MAXN) In[i-MAXN]=temp;
		else Pre[i]=temp;
	}
	if (i>MAXN) memmove(In,In+MAXN-i/2,sizeof(int)+i-MAXN);
	memmove(In,Pre+i/2,sizeof(int)+MAXN-i/2);
	n=i/2;
}

TREE* build(int Pb,int Pe,int Ib,int Ie) {
	if (Pb>Pe) return NULL;
	TREE *node=new TREE;
	int root=Pre[Pb],p=Ib;
	node->data=root;
	while (In[p]!=root) p++;
	int cur=p-Ib;
	node->left  = build(Pb+1,Pb+cur,Ib,p-1);
	node->right = build(Pb+cur+1,Pe,p+1,Ie);
	return node;
}

void PostOrder(TREE *now) {
	if (now->left)  PostOrder(now->left);
	if (now->right) PostOrder(now->right);
	printf("%d ",now->data);
}

int main() {
	freopen("1244.in","r",stdin);
	freopen("1244.out","w",stdout);
	read();
	root=build(0,n-1,0,n-1);
	PostOrder(root);
	return 0;
}
