#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e5 + 5;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int T, n, d[maxn], dep[maxn];
void dfs(int x, int fa) {
    int p = 0;
    dep[x] = dep[fa] + 1;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        dfs(ver[i], x);
        if(p == 0 || d[ver[i]] > d[p]) p = ver[i];
    }
    if(p) d[x] = d[p] + 1;
}
int c[maxn];
void Add(int x, int k) {
    for(; x <= n + 1; x += x & -x) c[x] += k;
}
int ask(int x) {
    int cnt = 0;
    for(; x; x -= x & -x) cnt += c[x];
    return cnt;
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    for(int i = 2; i <= n; i ++) {      
        if(dep[i] > 1) Add(1, 1), Add(dep[i], -1);
        Add(dep[i] + d[i] + 1, 1), Add(n + 1, -1); 
    }
    int ans = n;
    for(int i = 1; i <= n; i ++) ans = min(ans, ask(i));
    for(int i = 1; i <= n + 1; i ++) c[i] = 0;
    printf("%d\n", ans);
    for(int i = 1; i <= n; i ++) head[i] = 0, dep[i] = d[i] = 0;
    for(int i = 1; i <= tot; i ++) Next[i] = ver[i] = 0;
    tot = 0;
}
int main() {
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}