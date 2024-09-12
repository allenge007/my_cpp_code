#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
bool vis[maxn];
int head[maxn], ver[maxn << 1], Next[maxn], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x) {
    vis[x] = 1;
    for(int i = head[x]; i; i = Next[i]) {
        if(!vis[ver[i]]) dfs(ver[i]);
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        dfs(i);
        for(int j = 1; j <= n; j ++)
            if(vis[j]) ans ++, vis[j] = 0;
    }
    printf("%d", ans);
    return 0;
}