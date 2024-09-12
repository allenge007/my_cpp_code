#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, INF = 1e9 + 7;
pair<int, int> rain[maxn];
int maxi[maxn << 2], mini[maxn << 2], sum[maxn << 2], add1[maxn << 2], add2[maxn << 2], add[maxn << 2], l[maxn << 2], r[maxn << 2];
void build(int p, int l, int r) {
    if(l == r) {
        sum[p] = maxi[p] = mini[p] = add1[p] = add2[p] = add[p] = 0;
        mini[p] = add2[p] = INF;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    maxi[p] = mini[p] = sum[p] = add1[p] = add2[p] = add[p] = 0;
    mini[p] = add2[p] = INF;
}
void spread(int p) {
    if(add[p]) {
        sum[p << 1] += (r[p << 1] - l[p << 1] + 1) * add[p];
        sum[p << 1 | 1] += (r[p << 1 | 1] - l[p << 1 | 1] + 1) * add[p];
        add[p << 1] += add[p], add[p << 1 | 1] += add[p];
        add[p] = 0;
    }
    if(add1[p]) {
        maxi[p << 1] = maxi[p << 1 | 1] = add1[p << 1] = add1[p << 1 | 1] = add1[p];
        add1[p] = 0;
    }
    if(add2[p] != INF) {
        mini[p << 1] = mini[p << 1 | 1] = add2[p << 1] = add2[p << 1 | 1] = add2[p];
        add2[p] = INF;
    }
}
void update(int p) {
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
    maxi[p] = max(maxi[p << 1], maxi[p << 1 | 1]);
    mini[p] = min(mini[p << 1], mini[p << 1 | 1]);
}
void change(int p, int l, int r, int ql, int qr, int id) {
    if(l >= ql and r <= qr) {
        add1[p] = max(add1[p], id), add2[p] = min(add2[p], id), add[p] ++, sum[p] += (r - l + 1);
        return ;
    }
    spread(p);
    int mid = (l + r) >> 1;
    change(p << 1, l, mid, ql, qr, id);
    change(p << 1 | 1, mid + 1, r, ql, qr, id);
    update(p);
}
int ask(int p, int l, int r, int x) {
    
}
void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    build(1, 1, n);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d", &rain[i].first, &rain[i].second);
        change(1, 1, n, rain[i].first, rain[i].second, i);
    }

}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}