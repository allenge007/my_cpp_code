#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize(3)

inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn =  5e4 + 5, maxm = 2e5 + 5, BLOCK_SIZE = 550;
const long long mod = 1e9 + 7;
int n, q, a[maxn], root, lim, cnt;
long long ans[maxm];
struct node{
    int l, r, id;
}qury[maxm];
struct Segment_Tree{
    int ls, rs, l, r, num, tag;
    long long odd, even;
}t[maxn * 60];
void update(int p) {
    if(!t[p].ls) t[p].ls = ++ cnt;
    if(!t[p].rs) t[p].rs = ++ cnt;
    t[p].even = t[t[p].ls].even + t[t[p].rs].even;
    t[p].odd = t[t[p].ls].odd + t[t[p].rs].odd;
    t[p].num = t[t[p].ls].num + t[t[p].rs].num;
}
void spread(int p) {
    if(t[p].tag) {
        if(!t[p].ls) t[p].ls = ++ cnt;
        if(!t[p].rs) t[p].rs = ++ cnt;
        t[t[p].ls].tag ^= 1;
        t[t[p].rs].tag ^= 1;
        swap(t[t[p].ls].even, t[t[p].ls].odd);
        swap(t[t[p].rs].even, t[t[p].rs].odd);
        t[p].tag = 0;
    }
}
void change(int &p, int l, int r, int ql, int qr) {
    if(!p) p = ++ cnt;
    if(l >= ql && r <= qr) {
        swap(t[p].odd, t[p].even);
        t[p].tag ^= 1;
        return ;
    }
    spread(p); 
    int mid = (l + r) >> 1;
    if(ql <= mid) change(t[p].ls, l, mid, ql, qr);
    if(qr > mid) change(t[p].rs, mid + 1, r, ql, qr);
    update(p);
}
void insert0(int &p, int l, int r, int x, int k) {
    if(!p) p = ++ cnt;
    if(l == r) {
        t[p].even += x * k;
        t[p].num += k;
        return ;
    }
    spread(p);
    int mid = (l + r) >> 1;
    if(x <= mid) insert0(t[p].ls, l, mid, x, k);
    else insert0(t[p].rs, mid + 1, r, x, k);
    update(p);
    return ;
}
void insert1(int &p, int l, int r, int x, int k) {
    if(!p) p = ++ cnt;
    if(l == r) {
        t[p].odd += x * k;
        t[p].num += k;
        return ;
    }
    spread(p);
    int mid = (l + r) >> 1;
    if(x <= mid) insert1(t[p].ls, l, mid, x, k);
    else insert1(t[p].rs, mid + 1, r, x, k);
    update(p);
    return ;
}
int ask(int &p, int l, int r, int ql, int qr) {
    if(!p) p = ++ cnt;
    if(l >= ql && r <= qr) return t[p].num;
    spread(p);
    int mid = (l + r) >> 1, num = 0;
    if(ql <= mid) num += ask(t[p].ls, l, mid, ql, qr);
    if(qr > mid) num += ask(t[p].rs, mid + 1, r, ql, qr);
    update(p);
    return num;
}
void move(int p, int op) {
    if(a[p] + 1 <= lim) change(root, 0, lim, a[p] + 1, lim);
    // cout << "change " << a[p] + 1 << " " << lim << " " << t[root].even << " " << t[root].odd << endl;
    int num = 0;
    if(a[p] > 0) num = ask(root, 0, lim, 0, a[p] - 1);
    if(num & 1) insert0(root, 0, lim, a[p], op);
    else insert1(root, 0, lim, a[p], op);
    // cout << p << " " << op << " " << t[root].even << " " << t[root].odd << endl;
}
int main() {
    n = read(), q = read();
    for(int i = 0; i < n; i ++) a[i] = read(), lim = max(lim, a[i]);
    for(int i = 1; i <= q; i ++) {
        int l = read(), r = read();
        qury[i] = {l, r, i};
    }
    sort(qury + 1, qury + q + 1, [](node x, node y) {
        return x.l/BLOCK_SIZE == y.l/BLOCK_SIZE ? x.r < y.r : x.l/BLOCK_SIZE < y.l/BLOCK_SIZE;
    });
    int l = 0, r = -1;
    for(int i = 1; i <= q; i ++) {
        const node &qu = qury[i];
        while(l > qu.l) move(-- l, 1);
        while(r < qu.r) move(++ r, 1);
        while(l < qu.l) move(l ++, -1);
        while(r > qu.r) move(r --, -1);
        // cout << l << " " << r << " " << qury[i].id << " " << t[root].odd << endl;
        ans[qury[i].id] = t[root].odd;
    }
    for(int i = 1; i <= q; i ++) printf("%lld\n", ans[i] % mod);
    return 0;
}