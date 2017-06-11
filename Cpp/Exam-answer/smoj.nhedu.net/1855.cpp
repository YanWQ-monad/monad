// 1855.cpp
#include <cstring>
#include <cstdio>

const int MAXL = 55;
int r, s=1, ms, u, v, li, lp, sym_tot=0;
long long len[65536];
char inp[MAXL], pro[MAXL];

char GetChar(const int s, const int pos) {
	if (s == 0) return inp[pos-1];
	for (int i=0, cur_pos=0; i<lp; i++) {
		if (pro[i] == '$') {
			if ((long long)cur_pos + len[s-1] >= pos)
				return GetChar(s-1, pos - cur_pos);
			cur_pos += len[s-1];
		}
		else if (++cur_pos == pos) return pro[i];
	}
	return '-';
}

int main() {
	freopen("1855.in" , "r", stdin );
	freopen("1855.out", "w", stdout);
	
	scanf("%d", &r);
	while (r--) {
		scanf("%d %d %d", &ms, &u, &v);
		scanf("%s %s", inp, pro);
		len[0] = li = strlen(inp);
		lp =          strlen(pro);
		sym_tot = 0;
		for (int i=0; i<lp; i++)
			if (pro[i] == '$')
				sym_tot ++;
		if (sym_tot == 1) {
			for (int i=u; i<=v; i++)
				if (i <= li) putchar(inp[i-1]);
				else if (i <= (long long)(lp - sym_tot) * ms + li) putchar(pro[(i - li - 1) % (lp - sym_tot) + 1]);
				else putchar('-');
			puts("");
			continue;
		}
		for (s=1; s<ms && len[s-1]<=v; s++)
			len[s] = len[s-1] * sym_tot + (lp - sym_tot);
		for (int i=u; i<=v; i++)
			putchar(GetChar(s, i));
		puts("");
	}
	
	return 0;
}
