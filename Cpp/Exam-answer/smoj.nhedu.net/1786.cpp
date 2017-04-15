// 1786.cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::sort;

const int MAXN = 10010;
struct EXAM {
	char name[12];
	int wrn, tim, ac;
}stu[MAXN];
int n, m, k;
char tmp[15];

int StudentSort(const EXAM lhs, const EXAM rhs) {
	return (lhs.ac  != rhs.ac )? (lhs.ac  > rhs.ac ):
	       (lhs.tim != rhs.tim)? (lhs.tim < rhs.tim):
	       (strcmp(lhs.name, rhs.name) < 0);
}

void get(char *st) {
	char tmp = getchar();
	while (tmp == ' ' || tmp == '\n' || tmp == '\r')
		tmp = getchar();
	int cur=0;
	while (tmp != ' ' && tmp != -1 && tmp != '\n' && tmp != '\r') {
		st[cur++] = tmp;
		tmp = getchar();
	}
	st[cur++] = '\0';
}

int main() {
	freopen("1786.in" , "r", stdin );
	freopen("1786.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<k; i++) {
		scanf("%s", stu[i].name);
		for (int j=0, tim, wrn; j<n; j++) {
			tim = 0;
			get(tmp);
			if (strchr(tmp, '(') != NULL) {
				sscanf(tmp, "%d(%d)", &tim, &wrn);
				stu[i].ac ++;
			}
			else {
				sscanf(tmp, "%d", &wrn);
				if (wrn < 0) {
					wrn = 0;
				}
				else if (wrn > 0) {
					tim = wrn;
					wrn = 0;
					stu[i].ac ++;
				}
			}
			stu[i].wrn += wrn;
			stu[i].tim += tim;
		}
		stu[i].tim += stu[i].wrn * m;
	}
	sort(stu, stu+k, StudentSort);

	for (int i=0; i<k; i++) {
		printf("%-10s %2d %4d\n", stu[i].name, stu[i].ac, stu[i].tim);
	}

	return 0;
}
