#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w*10 + ch - '0', ch = getchar();
    return w*f;
}
const int mod = 998244353, maxn = 1e6 + 5;
inline int qpow(int x, int y) {
    int cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
int n, f[maxn], head[maxn], ver[maxn << 1], Next[maxn << 1], tot, siz[maxn];
pair<int, int> que[maxn];
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
inline int getfa(int x) {
    if(f[x] == x) return x;
    return f[x] = getfa(f[x]);
}
int d[maxn], fa[maxn];
void merge(int x, int y) {
    int r1 = getfa(x), r2 = getfa(y);
    if(d[r1] <= d[r2]) siz[r1] += siz[r2], f[r2] = r1;
    else siz[r2] += siz[r1], f[r1] = r2;
}
void dfs(int x, int Fa) {
    d[x] = d[Fa] + 1;
    fa[x] = Fa;
    for(int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if(y == Fa) continue;
        dfs(y, x);
    }
}
signed main() {
    n = read();
    for(int i = 1; i < n; i ++) {
        int x = read(), y = read();
        que[i] = make_pair(x, y);
    }
    for(int i = 1; i < n; i ++) {
        int x = read(), y = read();
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i ++) f[i] = i, siz[i] = 1;
    int ans = 1;
    for(int i = 1; i < n; i ++) {
        int x = getfa(que[i].first), y = getfa(que[i].second);
        if(d[x] > d[y]) swap(x, y);
        if(getfa(fa[f[y]]) != x) return printf("0\n"), 0;
        ans *= qpow(siz[x], mod - 2) * qpow(siz[y], mod - 2) % mod;
        ans %= mod;
        merge(x, y);
    }
    printf("%lld\n", ans);
    return 0;
}