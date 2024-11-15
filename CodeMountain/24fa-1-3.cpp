#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int h[maxn], n, head[maxn], Next[maxn << 1], ver[maxn << 1], tot, ans;
void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x, int fa) {
    if(h[x] > h[fa]) ans += h[x] - h[fa];
    for(int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}