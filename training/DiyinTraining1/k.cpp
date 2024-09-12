#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
int a[maxn], b[maxn];
vector<int> id[maxn];
struct node {
    int l, r, mini, num, add;
}t[maxn << 2];
void update(int p) {
    if(t[p << 1].mini == t[p << 1 | 1].mini) t[p].mini = t[p << 1].mini, t[p].num = t[p << 1].num + t[p << 1 | 1].num;
    else if(t[p << 1].mini < t[p << 1 | 1].mini) t[p].mini = t[p << 1].mini, t[p].num = t[p << 1].num;
    else t[p].mini = t[p << 1 | 1].mini, t[p].num = t[p << 1 | 1].num;
}
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r, t[p].add = 0;
    if(l == r) {
        t[p].num = 1, t[p].mini = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
void spread(int p) {
    if(t[p].add) {
        t[p << 1].mini += t[p].add;
        t[p << 1 | 1].mini += t[p].add;
        t[p << 1].add += t[p].add;
        t[p << 1 | 1].add += t[p].add;
        t[p].add = 0;
    }
}
void change(int p, int l, int r, int ql, int qr, int k) {
    if(t[p].l >= ql && t[p].r <= qr) {
        t[p].add += k;
        t[p].mini += k;
        return ;
    }
    spread(p);
    int mid = (l + r) >> 1;
    if(ql <= mid) change(p << 1, l, mid, ql, qr, k);
    if(qr > mid) change(p << 1 | 1, mid + 1, r, ql, qr, k);
    update(p);
}
int ask(int p, int l, int r, int ql, int qr) {
    if(t[p].l >= ql && t[p].r <= qr) {
        if(t[p].mini == 0) return t[p].num;
        return 0;
    }
    spread(p);
    int mid = (l + r) >> 1, cnt = 0;
    if(ql <= mid) cnt += ask(p << 1, l, mid, ql, qr);
    if(qr > mid) cnt += ask(p << 1 | 1, mid + 1, r, ql, qr);
    update(p);
    return cnt;
}
void solve() {
    int n = read(), m = read();
    // cout << n << " " << m << endl;
    for(int i = 1; i <= n; i ++) id[i].clear();
    for(int i = 1; i <= m; i ++) {
        a[i] = read(), b[i] = read();
        id[a[i]].push_back(i), id[b[i]].push_back(i);
        // cout << a[i] << " " << b[i] << endl;
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i ++) {
        for(auto j : id[i])
            if(a[j] == i) change(1, 1, n, a[j], b[j] - 1, 1);
    }
    int ans = ask(1, 1, n, 1, n);
    for(int i = 1; i < n; i ++) {
        for(auto j : id[i]) {
            if(a[j] == i) {
                change(1, 1, n, a[j], b[j] - 1, -1);
                if(a[j] > 1) change(1, 1, n, 1, a[j] - 1, 1);
                change(1, 1, n, b[j], n, 1);
            }
            else {
                if(a[j] > 1) change(1, 1, n, 1, a[j] - 1, -1);
                change(1, 1, n, b[j], n, -1);
                change(1, 1, n, a[j], b[j] - 1, 1);
            }
        }
        ans = max(ans, ask(1, 1, n, 1, n));
    }
    printf("%d\n", n - ans);
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}