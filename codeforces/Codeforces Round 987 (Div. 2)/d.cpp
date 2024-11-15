#include <bits/stdc++.h>

#define fir first
#define sec second

using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], n, ans[maxn];
pair<int, int> q[maxn];
struct node {
    int l, r, maxi, tag;
    bool del;
    node(int l = 0, int r = 0, int tag = 0, bool del = 0) : l(l), r(r), tag(tag), del(del) {}
}t[maxn << 2];
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r, t[p].maxi = 0, t[p].tag = 0, t[p].del = 0;
    if(l == r) {
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
void spread(int p) {
    if(t[p].del) {
        t[p].maxi = t[p].tag = 0;
        return ;
    }
    if(t[p].tag) {
        if(!t[p << 1].del) t[p << 1].maxi = t[p].tag, t[p << 1].tag = t[p].tag;
        if(!t[p << 1 | 1].del) t[p << 1 | 1].maxi = t[p].tag, t[p << 1 | 1].tag = t[p].tag;
        t[p].tag = 0;
    }
}
void update(int p) {
    t[p].del = t[p << 1].del & t[p << 1 | 1].del;
    t[p].maxi = 0;
    if(!t[p << 1].del) t[p].maxi = t[p << 1].maxi;
    if(!t[p << 1 | 1].del) t[p].maxi = t[p << 1 | 1].maxi;
}
int ask(int p, int l, int r, int ql, int qr) {
    if(t[p].del) return t[p].maxi = t[p].tag = 0;
    if(ql <= l && r <= qr) {
        return t[p].maxi;
    }
    spread(p);
    int mid = l + r >> 1, res = 0;
    if(ql <= mid) res = max(res, ask(p << 1, l, mid, ql, qr));
    if(qr > mid) res = max(res, ask(p << 1 | 1, mid + 1, r, ql, qr));
    return res;
}
void change(int p, int l, int r, int ql, int qr, int k) {
    if(t[p].del) return ;
    if(ql <= l && r <= qr) {
        t[p].maxi = k;
        t[p].tag = k;
        return ;
    }
    spread(p);
    int mid = l + r >> 1;
    if(ql <= mid) change(p << 1, l, mid, ql, qr, k);
    if(qr > mid) change(p << 1 | 1, mid + 1, r, ql, qr, k);
    update(p);
}
void del(int p, int l, int r, int k) {
    if(l == r) {
        t[p].del = 1;
        return ;
    }
    spread(p);
    int mid = l + r >> 1;
    if(k <= mid) del(p << 1, l, mid, k);
    else del(p << 1 | 1, mid + 1, r, k);
    update(p);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i], q[i] = {a[i], i};
    sort(q + 1, q + n + 1, greater<pair<int, int>>());
    build(1, 1, n);
    for(int i = 1; i <= n; i ++) {
        int k = max(q[i].fir, ask(1, 1, n, q[i].sec, n));
        ans[q[i].sec] = k;
        change(1, 1, n, q[i].sec, n, k);
        del(1, 1, n, q[i].sec);
    }
    for(int i = 1; i <= n; i ++) cout << ans[i] << " ";
    cout << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}