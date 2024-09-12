#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
const long long INF = 1e18 + 7;
int head[maxn], ver[maxn << 1], Next[maxn << 1], tot, siz[maxn];
int n, m, c;
long long ans;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x, int fa) {
    siz[x] = 1;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        dfs(ver[i], x);
        siz[x] += siz[ver[i]];
        ans = min(ans, 1ll * (n - siz[ver[i]]) * (n - siz[ver[i]]) + 1ll * siz[ver[i]] * siz[ver[i]]);
    }
}
void solve() {
    ans = INF;
    scanf("%d%d%d", &n, &m, &c);
    for(int i = 1; i <= n; i ++) head[i] = 0;
    for(int i = 1; i <= tot; i ++) ver[i] = Next[i] = 0;
    tot = 0;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}