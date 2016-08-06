// 1251.cpp
#include <cstring>
#include <cstdio>

char temp[64];
short keyboard[128];
int finger[9];
void init(const char *keys,int finger) {
	for (int i=0;keys[i]!='\0';i++)
		keyboard[(int)keys[i]]=finger;
}
int main() {
	freopen("1251.in","r",stdin);
	freopen("1251.out","w",stdout);
	init(" 1QAZ",1);
	init("2WSX",2);
	init("3EDC",3);
	init("4RFV5TGB",4);
	init("6YHN7UJM",5);
	init("8IK,",6);
	init("9OL.",7);
	init("0P;/\'[]-=",8);
	char temp;
	while ((temp=getchar())!=-1)
		finger[keyboard[(int)temp]]++;
	for (int i=1;i<=8;i++)
		printf("%d\n",finger[i]);
	return 0;
}
