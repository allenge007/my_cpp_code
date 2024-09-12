#include <bits/stdc++.h>

using namespace std;
const int maxn 1e5 + 5;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int n, m, u[maxn], v[maxn], Lca[maxn], d[maxn], f[maxn][20];
void dfs(int x, int fa) {
    f[x][0] = fa;
    for(int i = 1; i < 20; i ++) f[x][i] = f[f[x][i - 1]][i - 1];
    d[x] = d[fa] + 1;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        dfs(ver[i], x);
    }  
}
int lca(int x, int y) {
    if(d[x] < d[y]) swap(x, y);
    for(int i = 19; i >= 0; i --) {
        if(d[f[x][i]] >= d[y]) x = f[x][i];
    }
    if(x == y) return x;
    for(int i = 19; i >= 0; i --) {
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
bool check(int mid) {
    for(int i = 1; i <= n; i ++) {
        
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d",. &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 1);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d", &u[i], &v[i]);
        Lca[i] = lca(u[i], v[i]);
    }
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}