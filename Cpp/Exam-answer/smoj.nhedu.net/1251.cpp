// 1251.cpp
#include <cstdio>

int finger[9];
short key[]={8,0,0,0,0,6,8,7,8,8,1,2,3,4,4,5,5,6,7,0,8,0,8,0,0,0,1,4,3,3,3,4,4,5,6,5,6,7,5,5,7,8,1,4,2,4,5,4,2,2,5,1,8,0,8};
#define keys(x) key[x-'\'']
int main() {
	freopen("1251.in","r",stdin);
	freopen("1251.out","w",stdout);
	char temp;
	while ((temp=getchar())!=-1)
		finger[keys(temp)]++;
	for (int i=1;i<=8;i++)
		printf("%d\n",finger[i]);
	return 0;
}
