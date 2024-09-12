#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int n, q, f[maxn][20], dfn[maxn], cnt, trans[maxn], d[maxn];
void dfs(int x) {
    dfn[x] = ++ cnt, d[x] = d[f[x][0]] + 1, trans[cnt] = x;
    for(int i = 1; i < 20; i ++) f[x][i] = f[f[x][i - 1]][i - 1];
    for(int i = head[x]; i; i = Next[i]) {
        dfs(ver[i]);
    }
}
int lca(int x, int y) {
    if(d[x] > d[y]) swap(x, y);
    for(int i = 19; i >= 0; i --) if(d[f[y][i]] >= d[x]) y = f[y][i];
    if(x == y) return x;
    for(int i = 19; i >= 0; i --) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
struct Tree{
    int l, r;
    pair<int, int> mini, maxi;
}t[maxn << 2];
void update(int p) {
    t[p].mini = min(t[p << 1].mini, t[p << 1 | 1].mini);
    t[p].maxi = max(t[p << 1].maxi, t[p << 1 | 1].maxi);
}
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if(l == r) {
        t[p].mini = t[p].maxi = make_pair(dfn[l], l);
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
pair<int, int> ask1(int p, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) {
        return t[p].mini;
    }
    int mid = (l + r) >> 1;
    pair<int, int> ans = {maxn, maxn};
    if(ql <= mid) ans = ask1(p << 1, l, mid, ql, qr);
    if(qr > mid) ans = min(ans, ask1(p << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}
pair<int, int> ask2(int p, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) {
        return t[p].maxi;
    }
    int mid = (l + r) >> 1;
    pair<int, int> ans = {0, 0};
    if(ql <= mid) ans = ask2(p << 1, l, mid, ql, qr);
    if(qr > mid) ans = max(ans, ask2(p << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}
int qlca(int l, int r, int v) {
    // cout << l << " " << r << " " << v << " ";
    pair<int, int> mini = {maxn, maxn}, maxi = {0, 0};
    if(v - 1 >= l) mini = ask1(1, 1, n, l, v - 1), maxi = ask2(1, 1, n, l, v - 1);
    if(v + 1 <= r) mini = min(ask1(1, 1, n, v + 1, r), mini), maxi = max(ask2(1, 1, n, v + 1, r), maxi);
    // cout << mini.second << " " << maxi.second << endl;;
    return lca(mini.second, maxi.second);
}
int main() {
    scanf("%d%d", &n, &q);
    for(int i = 2; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        add(x, i);
        f[i][0] = x;
    }
    dfs(1);
    // for(int i = 1; i <= n; i ++) cout << dfn[i] << " ";
    // cout << endl;
    build(1, 1, n);
    while(q --) {
        int l, r;
        scanf("%d%d", &l, &r);
        auto pmin = ask1(1, 1, n, l, r);
        auto pmax = ask2(1, 1, n, l, r);
        int lca1, lca2;
        // cout << pmin.second << " " << pmax.second << endl;
        lca1 = qlca(l, r, pmin.second);
        lca2 = qlca(l, r, pmax.second);
        // cout << " " << lca1 << " " << lca2 << endl;
        printf("%d\n", d[lca1] > d[lca2] ? d[lca1] - 1 : d[lca2] - 1);
    }
    return 0;
}