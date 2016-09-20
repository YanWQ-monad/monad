// 1406.cpp
#include <cstdio>

char st[128];
int sum=0;
int root(int sum) {
	int ret=0;
	while (sum) {
		ret += sum%10;
		sum = sum/10;
	}
	return ret;
}
int main() {
	freopen("1406.in","r",stdin);
	freopen("1406.out","w",stdout);
	fgets(st,sizeof(st),stdin);
	for (int i=0; st[i]>='0' && st[i]<='9'; i++)
		sum += st[i]-'0';
	while ((sum = root(sum))>9);
	printf("%d\n",sum);
	return 0;
}
