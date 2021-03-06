// 1267.cpp
#include <cstring>
#include <cstdio>
#define min(x,y) ((x)<(y)? (x):(y))

static const char binary[30][52]={
                                                "1",
                                              "101",
                                            "11001",
                                          "1111101",
                                       "1001110001",
                                     "110000110101",
                                   "11110100001001",
                                "10011000100101101",
                              "1011111010111100001",
                            "111011100110101100101",
                         "100101010000001011111001",
                       "10111010010000111011011101",
                     "1110100011010100101001010001",
                  "1001000110000100111001110010101",
                "101101011110011000100000111101001",
              "11100011010111111010100100110001101",
           "10001110000110111100100110111111000001",
         "1011000110100010101111000010111011000101",
       "110111100000101101101011001110100111011001",
    "100010101100011100100011000001001000100111101",
  "10101101011110001110101111000101101011000110001",
"1101100011010111001001101011011100010111011110101"};
static const int binLen[22]={1,3,5,7,10,12,14,17,19,21,24,26,28,31,33,35,38,40,42,45,47,49};
char temp[52],t[52];
int r,f[52];
void read(int *Len) {
	scanf("%d",Len);
	getchar();
	memset(temp,0,sizeof(temp));
	scanf("%s",temp);
}
void dp(int Len) {
	f[0]=0;
	for (int i=1;i<=Len;i++) {
		f[i]=-1;
		for (int j=21;j>=0;j--) {
			if (i-binLen[j]<0 || temp[Len-i]=='0' || f[i-binLen[j]]==-1) continue;
			memset(t,0,sizeof(t));
			strncpy(t,temp+Len-i,binLen[j]);
			if (strcmp(t,binary[j])) continue;
			f[i] = f[i]==-1? f[i-binLen[j]]+1:min(f[i],f[i-binLen[j]]+1);
		}
	}
}
int main() {
	freopen("1267.in","r",stdin);
	freopen("1267.out","w",stdout);
	scanf("%d",&r);
	for (int rt=0,l;rt<r;rt++) {
		memset(f,0,sizeof(f));
		read(&l);
		dp(l);
		printf("%d\n",f[l]);
	}
	return 0;
}
