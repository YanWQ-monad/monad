// 1018.cpp
#include <cstdio>

int z[1000005],d[1005],n;
bool bo;
int main() {
	freopen("1018.in","r",stdin);
	freopen("1018.out","w",stdout);
	scanf("%d",&n);
	for	(int i=0;i<n;i++) {
		scanf("%d",&z[i]);
		d[z[i]]++;
	}
	for	(int i=0;i<n;i++)
		if	(d[z[i]]==1) {
			bo=true;
			printf("%d",z[i]);
			break;
		}
	if	(!bo)
		printf("0");
	return 0;
}
