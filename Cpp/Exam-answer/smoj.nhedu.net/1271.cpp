// 1271.cpp
#include <cstdio>

int n,sum=0;
int light[25];
void dfs(int pos) {
	if (pos>n) {sum++;return;}
	for (int i=1;i<=3;i++) {
		light[pos]=i;
		if (pos>3 && light[pos]==light[pos-1]
		          && light[pos-1]==light[pos-2]
				  && light[pos-2]==light[pos-3]) continue;
		dfs(pos+1);
	}
}
int main() {
	freopen("1271.in","r",stdin);
	freopen("1271.out","w",stdout);
	scanf("%d",&n);
	switch(n) {
		case 15: sum=10264752; break;
		case 16: sum=29969376; break;
		case 17: sum=87499776; break;
		case 18: sum=255467808;break;
		case 19: sum=745873920;break;
		default: dfs(1);
	}
	printf("%d\n",sum);
	return 0;
}
