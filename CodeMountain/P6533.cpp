#include <bits/stdc++.h>

using namespace std;
#define min(a, b) (a < b ? a : b)
const int maxn = 1e5 + 1, mod = 1e4 + 7;
struct node{
    short l, r, ans[21];
    node(int l = 0, int r = 0) : l(l), r(r) {}
}t[maxn << 2];
int a[maxn], b[maxn], n, c;
void update(int p) {
    for(int i = 0; i <= c; i ++) t[p].ans[i] = 0;
    for(int i = 0; i <= c; i ++) {
        for(int j = 0; j <= c; j ++) {
            t[p].ans[min(i + j, c)] += (int) t[p << 1].ans[i] * t[p << 1 | 1].ans[j] % mod;
            t[p].ans[min(i + j, c)] %= mod;
        }
    }
}
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if(l == r) {
        t[p].ans[0] = b[l] % mod;
        t[p].ans[1] = a[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
void change(int p, int l, int r, int x) {
    if(l == r) {
        t[p].ans[0] = b[l] % mod;
        t[p].ans[1] = a[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) change(p << 1, l, mid, x);
    else change(p << 1 | 1, mid + 1, r, x);
    update(p);
}
int main() {
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i ++) {
        int p, ap, bp;
        scanf("%d%d%d", &p, &ap, &bp);
        a[p] = ap, b[p] = bp;
        change(1, 1, n, p);
        printf("%u\n", t[1].ans[c]);
    }
    return 0;
}