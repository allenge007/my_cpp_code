#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
int opt[maxn], x[maxn], y[maxn], id[maxn], head[maxn], ver[maxn << 1], Next[maxn << 1], tot;
int siz[maxn], d[maxn], top[maxn], cnt, f[maxn], son[maxn], L[maxn], R[maxn];
long long  val[maxn], tmp[maxn], tag[maxn];
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x, int fa){
    f[x] = fa;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        dfs(ver[i], x);
        siz[x] += siz[ver[i]], d[ver[i]] = d[x] + 1;
        if(siz[ver[i]] > siz[son[x]])
            son[x] = ver[i];
    }
}
void dfs2(int x, int t) {
    top[x] = t, id[x] = ++ cnt, val[cnt] = 0;
    if(!son[x]) return ;
    dfs2(son[x], t);
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == son[x] or ver[i] == f[x]) continue;
        dfs2(ver[i], ver[i]);
    }
}
void update(int p) {
    val[p] = val[p << 1] + val[p << 1 | 1];
}
void build(int p, int l, int r) {
    L[p] = l, R[p] = r;
    if(l == r) {
        val[p] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
    tag[p] = 0;
}
void spread(int p) {
    if(tag[p]) {
        val[p << 1] += tag[p] * (R[p << 1] - L[p << 1] + 1);
        val[p << 1 | 1] += tag[p] * (R[p << 1 | 1] - L[p << 1 | 1] + 1);
        tag[p << 1] += tag[p], tag[p << 1 | 1] += tag[p];
        tag[p] = 0;
    }
}
void change(int p, int l, int r, int ql, int qr, int k) {
    if(l >= ql and r <= qr) {
        val[p] += (long long)k * (r - l + 1);
        tag[p] += k;
        return ;
    }
    spread(p);
    int mid = (l + r) >> 1;
    if(ql <= mid) change(p << 1, l, mid, ql, qr, k);
    if(qr > mid) change(p << 1 | 1, mid + 1, r, ql, qr, k);
    update(p);
}
long long ask(int p, int l, int r, int ql, int qr) {
    if(l >= ql and r <= qr) {
        return val[p];
    }
    spread(p);
    int mid = (l + r) >> 1;
    long long ans = 0;
    if(ql <= mid) ans += ask(p << 1, l, mid, ql, qr);
    if(qr > mid) ans += ask(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}
void solve() {
    int n = 1, q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i ++) {
        scanf("%d", &opt[i]);
        if(opt[i] == 1) {
            scanf("%d", &x[i]);
            add(x[i], ++ n);
            add(n, x[i]);
            id[x[i]] = n;
        }
        else {
            scanf("%d%d", &x[i], &y[i]);
        }
    }
    dfs(1, 1);
    dfs2(1, 1);
    for(int i = 1; i <= q; i ++) {
        if(opt[i] == 1) {
            tmp[id[x[i]]] = ask(1, 1, n, id[x[i]], id[x[i]] +  siz[id[x[i]]] - 1);
        }
        else {
            change(1, 1, n, id[x[i]], id[x[i]] + siz[x[i]] - 1, y[i]);
        }
    }
    for(int i = 1; i <= n; i ++) {
        printf("%lld ", ask(1, 1, n, i, i) - tmp[i]);
    }
    printf("\n");
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}