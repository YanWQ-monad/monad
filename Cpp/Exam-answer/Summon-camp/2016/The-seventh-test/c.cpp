// c.cpp
#include <cstdio>

int tInt,n,m,r,sum[103][103],px,py,ans;
char tChar;
bool fly[103][103];
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d %d %d",&n,&m,&r);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			tChar=getchar();
			while (tChar!='*' && tChar!='.') tChar=getchar();
			if (tChar=='*') fly[i][j]=true;
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+fly[i][j];
		}
	px=py=r;
	for (int i=r;i<=n;i++)
		for (int j=r;j<=m;j++) {
			tInt=sum[i-1][j-1]-sum[i-r+1][j-1]-sum[i-1][j-r+1]+sum[i-r+1][j-r+1];
			if (tInt > ans) {
				ans=tInt;
				px=i;
				py=j;
			}
		}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if      (i==px-r+1 && j>py-r+1 && j<py) putchar('-');	// Up
			else if (i==px && j>py-r+1 && j<py)     putchar('-');	// Down
			else if (j==py-r+1 && i>px-r+1 && i<px) putchar('|');   // Left
			else if (j==py && i>px-r+1 && i<px)     putchar('|');   // Right
			else if (i==px-r+1 && j==py-r+1)        putchar('+');   // Left-up
			else if (i==px && j==py-r+1)            putchar('+');   // Left-down
			else if (i==px-r+1 && j==py)            putchar('+');   // Right-up
			else if (i==px && j==py)                putchar('+');   // Right-down
			else if (fly[i][j])                     putchar('*');   // Fly
			else                                    putchar('.');   // Air
		}
		putchar('\n');
	}
	return 0;
}
