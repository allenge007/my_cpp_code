#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const long long INF = 1e9 + 7;
int n, ans[maxn], tot, root;
struct tree{
    int ls, rs, maxi;
    tree(int ls = 0, int rs = 0, int maxi = 0) : ls(ls), rs(rs), maxi(maxi) {}
}t[maxn * 31];
struct node{
    int a, b, id;
    node(int a = 0, int b = 0, int id = 0) : a(a), b(b), id(id) {}
}d[maxn];
bool cmp1(node x, node y) {
    return x.a == y.a ? x.b < y.b : x.a < y.a;
}
bool cmp2(node x, node y) {
    return x.b == y.b ? x.a < y.a : x.b < y.b;
}
void update(int p) {
    t[p].maxi = max(t[t[p].ls].maxi, t[t[p].rs].maxi);
}
void add(int &p, int l, int r, int k, int v) {
    if(!p) p = ++ tot;
    if(l == r) {
        t[p].maxi = max(t[p].maxi, v);
        return ;
    }
    int mid = (l + r) >> 1;
    if(k <= mid) add(t[p].ls, l, mid, k, v);
    else add(t[p].rs, mid + 1, r, k, v);
    update(p);
}
int ask(int p, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) {
        return t[p].maxi;
    }
    int mid = (l + r) >> 1, cnt = 0;
    if(ql <= mid && t[p].ls) cnt = max(cnt, ask(t[p].ls, l, mid, ql, qr));
    if(qr > mid && t[p].rs) cnt = max(cnt, ask(t[p].rs, mid + 1, r, ql, qr));
    return cnt;
}
signed main() {
    int maxi = 0;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        d[i] = node(x, y, i);
        ans[i] = 2 * INF, maxi = max(maxi, y);
    }
    sort(d + 1, d + n + 1, cmp1);
    int maxy = -INF;
    for(int i = n; i >= 1; i --) {
        if(maxy < d[i].b) ans[d[i].id] = min(ans[d[i].id], d[i].b - maxy);
        else ans[d[i].id] = 0;
        if(d[i].a == d[i - 1].a && d[i].b == d[i - 1].b) ans[d[i].id] = 0;
        maxy = max(maxy, d[i].b);
    }
    sort(d + 1, d + n + 1, cmp2);
    int maxx = -INF;
    for(int i = n; i >= 1; i --) {
        if(maxx < d[i].a) ans[d[i].id] = min(ans[d[i].id], d[i].a - maxx);
        else ans[d[i].id] = 0;
        maxx = max(maxx, d[i].a);
    }
    sort(d + 1, d + n + 1, cmp1);
    for(int i = 1; i <= n; i ++) {
        if(i > 1) {
            int mini = ask(root, 1, maxi, 1, d[i].b);
            if(mini) ans[d[i].id] = min(ans[d[i].id], d[i].a + d[i].b - mini);
        }
        add(root, 1, maxi, d[i].b, d[i].a + d[i].b);
    }
    for(int i = 1; i <= n; i ++) printf("%lld ", ans[i]);
    return 0;
}