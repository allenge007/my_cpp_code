#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 2e5 + 5, maxm = 1e6 + 6, BLOCK_SIZE = 300;
struct node {
    int l, r, id;
    bool operator <(const node &x) const {
        return l / BLOCK_SIZE ^ x.l / BLOCK_SIZE ? l < x.l : (l / BLOCK_SIZE & 1 ? r < x.r : r > x.r);
    }
}qury[maxn];
int a[maxn], c[maxm], ans, qans[maxn];
void insert(int p) {
    c[p] ++;
    if(c[p] & 1) ans ++;
    else ans --;
}
void erase(int p) {
    c[p] --;
    if(c[p] & 1) ans ++;
    else ans --;
}
void solve() {
    int n = read(), q = read();
    int maxi = 0;
    for(int i = 1; i <= n; i ++) a[i] = read(), maxi = max(maxi, a[i]);
    for(int i = 1; i <= maxi; i ++)  c[i] = 0;
    for(int i = 1; i <= q; i ++) qury[i].l = read(), qury[i].r = read(), qury[i].id = i;
    sort(qury + 1, qury + q + 1);
    int l = 1, r = 0;
    ans = 0;
    for(int i = 1; i <= q; i ++) {
        while(r < qury[i].r) insert(a[++ r]);
        while(l > qury[i].l) insert(a[-- l]);
        while(r > qury[i].r) erase(a[r --]);
        while(l < qury[i].l) erase(a[l ++]);
        qans[qury[i].id] = ans;
    }
    for(int i = 1; i <= q; i ++) printf(qans[i] ? "no\n" : "yes\n");
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}