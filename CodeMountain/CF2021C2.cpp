#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, q, a[maxn], b[maxn], rak[maxn];
set<int> g[maxn];
class node {
public:
    int x, y, val;
    node(int x = 0, int y = 0, int val = 0): x(x), y(y), val(val) {}
    bool operator < (const node &rhs) const {
        return val == rhs.val ? (x == rhs.x ? y < rhs.y : x < rhs.x) : val < rhs.val;
    }
};
void solve() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), rak[a[i]] = i, g[i].clear();
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]), b[i] = rak[b[i]], g[b[i]].insert(i);
    for(int i = 1; i <= n; i ++) g[i].insert(m + 1); 
    set<node> s;
    for(int i = 2; i <= n; i ++) s.insert(node(i - 1, i, *g[i].begin() - *g[i - 1].begin()));
    if(s.begin() -> val < 0) puts("tidak");
    else puts("ya");
    for(int i = 1; i <= q; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        y = rak[y];
        bool flag = 0;
        if(*g[b[x]].begin() == x) {
            flag = 1;
            if(b[x] > 1) s.erase(node(b[x] - 1, b[x], *g[b[x]].begin() - *g[b[x] - 1].begin()));
            if(b[x] < n) s.erase(node(b[x], b[x] + 1, *g[b[x] + 1].begin() - *g[b[x]].begin()));
        }
        g[b[x]].erase(x);
        if(flag) {
            if(b[x] > 1) s.insert(node(b[x] - 1, b[x], *g[b[x]].begin() - *g[b[x] - 1].begin()));
            if(b[x] < n) s.insert(node(b[x], b[x] + 1, *g[b[x] + 1].begin() - *g[b[x]].begin()));
        }
        flag = 0;
        if(x < *g[y].begin()) {
            flag = 1;
            if(y > 1) s.erase(node(y - 1, y, *g[y].begin() - *g[y - 1].begin()));
            if(y < n) s.erase(node(y, y + 1, *g[y + 1].begin() - *g[y].begin()));
        }
        g[y].insert(x);
        if(flag) {
            if(y > 1) s.insert(node(y - 1, y, *g[y].begin() - *g[y - 1].begin()));
            if(y < n) s.insert(node(y, y + 1, *g[y + 1].begin() - *g[y].begin()));
        }
        b[x] = y;
        if(s.begin() -> val < 0) puts("tidak");
        else puts("ya");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}