#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 3e5 + 5;
int head[maxn], ver[maxn << 1], Next[maxn << 1], tot, col[maxn];
bool vis[maxn];
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x, int fa) {
    bool flag = 1;
    vis[x] = 1;
    // cout << x << " " <<fa << endl;
    for(int i = head[x]; i; i = Next[i]) {
        if(col[ver[i]]) {
            flag = 0;
        }
    }
    if(flag) col[x] = 1;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] != fa && !vis[ver[i]]) dfs(ver[i], x);
    }
}
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) head[i] = 0;
    for(int i = 1; i <= tot; i ++) ver[i] = Next[i] = 0;
    tot = 0;
    for(int i = 1; i <= m; i ++) {
        int x = read(), y = read();
        add(x, y), add(y, x);
    }
    for(int i = 1; i <= n; i ++) vis[i] = col[i] = 0;
    dfs(1, 0);
    bool flag = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(!vis[i]) flag = 0;
    if(flag) {
        for(int i = 1; i <= n; i ++) if(col[i]) cnt ++;
        printf("YES\n%d\n", cnt);
        for(int i = 1; i <= n; i ++) if(col[i]) printf("%d ", i);
        printf("\n");
    }
    else printf("NO\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}