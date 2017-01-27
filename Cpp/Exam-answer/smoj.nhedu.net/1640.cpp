// 1640.cpp
#include <algorithm>
#include <cstdio>
using std::min;

const int INF  = 0x7FFFFFFF;
const int MAXN = 100010;
const int MAXH = 1000007;

template<typename T, int MAXL>
class mHash {
 private:
    int table[MAXL];
    T con[MAXL];
    bool effe[MAXL];
    int hash(const int num) const {
        // int pos = ((num ^ (num >> 16)) & (1 << 16)) % MAXL;
        int pos = num % MAXL;
        while (table[pos] != num && effe[pos]) {
            pos ++;
            if (pos >= MAXL) pos = 0;
        }
        return pos;
    }
 public:
    T  operator[](const int pos) const {
        int _pos = hash(pos);
        if (!effe[pos])
            return INF;
        return con[_pos];
    }
    T& operator[](const int pos) {
        int _pos = hash(pos);
        table[_pos] = pos;
        effe[_pos] = true;
        return con[_pos];
    }
};

struct NODE { int x, y; } node[MAXN];
mHash<int, MAXH> xp, yp;
int n, xs, ys, xe, ye, ans;

int main() {
    freopen("1640.in" , "r", stdin );
    freopen("1640.out", "w", stdout);
    
    scanf("%d %d %d %d %d", &n, &xs, &ys, &xe, &ye);
    xp[xe] = yp[ye] = INF;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &node[i].x, &node[i].y);
        yp[node[i].y] = xp[node[i].x] = INF;
    }
    
    xp[xs] = 0;
    yp[ys] = 0;
    for (bool edit=true; edit; ) {
        edit = false;
        for (int i=0; i<n; i++) {
            if (xp[node[i].x] != INF && xp[node[i].x] + 1 < yp[node[i].y]) {
                yp[node[i].y] = xp[node[i].x] + 1;
                edit = true;
            }
            if (yp[node[i].y] != INF && yp[node[i].y] + 1 < xp[node[i].x]) {
                xp[node[i].x] = yp[node[i].y] + 1;
                edit = true;
            }
        }
    }
    
    ans = min(xp[xe], yp[ye]);
    printf("%d", ans == INF? -1:ans);
    
    return 0;
}
