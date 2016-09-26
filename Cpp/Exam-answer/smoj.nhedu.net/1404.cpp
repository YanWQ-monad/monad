// 1404.cpp
#include <algorithm>
#include <cstdio>
#include <queue>
using std::sort;
using std::max;
static const int DayInMonth[]={0,31,59,90,120,151,181,212,243,273,304,334};

struct PRODUCT {
	int start,days;
	double profit;
	void SetStartMMDD(int MMDD) {
		start = DayInMonth[MMDD / 100 - 1] + (MMDD % 100);
	}
}duct[16];
int ProductSort(PRODUCT lhs, PRODUCT rhs) {
	if (lhs.start != rhs.start) return lhs.start < rhs.start;
	return lhs.days < rhs.days;
}
int n;
double money[370];
int main() {
	freopen("1404.in", "r", stdin);
	freopen("1404.out", "w", stdout);
	scanf("%d", &n);
	for (int i=0,temp; i<n; i++) {
		scanf("%d %d %lf", &temp, &duct[i].days, &duct[i].profit);
		duct[i].profit = duct[i].profit / 100.0;
		duct[i].SetStartMMDD(temp);
	}
	sort(duct, duct+n, ProductSort);
	for (int i=0, pos; i<n; i++) {
		double MaxMoney = 100000.0;
		for (int j=1; j<duct[i].start; j++)
			MaxMoney = max(MaxMoney, money[j]);
		pos = duct[i].start + duct[i].days - 1;
		money[pos] = max(money[pos], MaxMoney * (1 + duct[i].profit * duct[i].days / 365));
	}
	double MaxMoney = 0.0;
	for (int i=0; i<=365; i++)
		MaxMoney = max(MaxMoney, money[i]);
	printf("%.2lf", MaxMoney);
	return 0;
}
