// 1249.cpp
#include <cstring>
#include <cstdio>

#define en(i) en_US[i-'a']
#define same(i) msame[i-'a']
const char en_US[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
const char msame[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int map[9];
char st[120];
int main() {
	freopen("1249.in","r",stdin);
	freopen("1249.out","w",stdout);
	for (int i=0,temp;i<9;i++) {
		scanf("%d",&temp);
		map[temp]=i+1;
	}
	getchar();
	gets(st);
	int size=strlen(st);
	for (int i=0;i<size;i++) {
		if (i>0 && same(st[i])==same(st[i-1]))
			printf("#");
		for (int j=0;j<en(st[i]);j++)
			printf("%d",map[(int)same(st[i])]);
	}
	return 0;
}
