#include <algorithm>
#include <cstring>
#include <cstdio>
using std::min;

const int MAXL = 53 , MAXD = 100;
int r,n,f[MAXL],dsLen[MAXD];
char st[MAXL],ds[MAXD][MAXL],SNTemp[26],DPTemp[MAXL];
short sumDs[MAXD][26];
void read() {
	scanf("%s %d",st,&n);
	for (int i=0;i<n;i++)
		scanf("%s",ds[i]);
}
void init() {
	memset(sumDs,0,sizeof(sumDs));
	for (int i=0;i<n;i++) {
		dsLen[i]=strlen(ds[i]);
		for (int j=0;j<dsLen[i];j++)
			sumDs[i][ds[i][j]-'a']++;
	}
}
int sensitiveNum(const char *lhs,const int Len,const int sP) {
	if (Len!=dsLen[sP]) return -1;
	memset(SNTemp,0,sizeof(SNTemp));
	int val=0;
	for (int i=0;i<Len;i++) {
		SNTemp[lhs[i]-'a']++;
		val += lhs[i]!=ds[sP][i];
	}
	for (int i=0;i<26;i++)
		if (sumDs[sP][i]!=SNTemp[i])
			return -1;
	return val;
}
int BadNum(const char *st,const int Len) {
	int ret=-1,temp;
	for (int i=0;i<n;i++) {
		temp=sensitiveNum(st,Len,i);
		ret = temp==-1? ret:(ret==-1? temp:min(ret,temp));
	}
	return ret;
}
void dp() {
	int Len=strlen(st);
	f[0]=0;
	for (int i=1,Error;i<=Len;i++) {
		f[i]=-1;
		for (int j=0;j<n;j++) {
			if (dsLen[j]>i || f[i-dsLen[j]]==-1) continue;
			strncpy(DPTemp,st+i-dsLen[j],dsLen[j]);
			if ((Error=BadNum(DPTemp,dsLen[j])) != -1)
				f[i]= f[i]==-1? Error+f[i-dsLen[j]]:min(f[i],Error+f[i-dsLen[j]]);
		}
	}
}
int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&r);
	getchar();
	for (int rt=0;rt<r;rt++) {
		read();
		init();
		dp();
		printf("%d\n",f[strlen(st)]);
	}
	return 0;
}
