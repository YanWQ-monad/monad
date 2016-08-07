// mobitel.cpp
#include <cstring>
#include <cstdio>

const char   en[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
const char same[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int map[9];
char st[120];
int main() {
	freopen("mobitel.in","r",stdin);
	freopen("mobitel.out","w",stdout);
	for (int i=0,temp;i<9;i++) {
		scanf("%d",&temp);
		map[temp]=i+1;
	}
	getchar();
	gets(st);
	int size=strlen(st);
	for (int i=0;i<size;i++) {
		if (i>0 && same[st[i]-'a']==same[st[i-1]-'a'])
			printf("#");
		for (int j=0;j<en[st[i]-'a'];j++)
			printf("%d",map[(int)same[(int)st[i]-'a']]);
	}
	return 0;
}
