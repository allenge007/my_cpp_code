#include <bits/stdc++.h>

using namespace std;
inline int read(){
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 2e3 + 5;
int n, head[maxn], Next[maxn << 1], ver[maxn << 1], tot;
int d[maxn], f[maxn];
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x, int fa) {
    f[x] = fa;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        d[ver[i]] = d[x] + 1;
        dfs(ver[i], x);
    }
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    int p = 0;
    d[1] = 1, dfs(1, 0);
    for(int i = 1; i <= n; i ++) if(d[i] > d[p] or !p) p = i;
    d[p] = 1, dfs(p, 0), p = 0;
    for(int i = 1; i <= n; i ++) if(d[i] > d[p] or !p) p = i;
    int x = p;
    if(d[p] & 1) {
        int tmp = d[p]/2, x = p;
        while(tmp --) x = f[x];
        printf("%d\n", d[p]/2 + 1);
        for(int i = 0; i <= d[p]/2; i ++) {
            printf("%d %d\n", x, i);
        }
    }
    else {
        int tmp = d[p]/2 - 1;
        while(tmp --) x = f[x];
        if(d[p] % 4 == 0) {
            printf("%d\n", d[p]/2);
            for(int i = 1; i <= d[p]/2 - 1; i += 2) {
                printf("%d %d\n%d %d\n", x, i, f[x], i);
            }
        }
        else {
            printf("%d\n", d[p]/2 + 1);
            for(int i = 0; i <= d[p]/2; i ++) {
                printf("%d %d\n", x, i);
            }
        }
    }
    for(int i = 1; i <= n; i ++) head[i] = 0;
    for(int i = 1; i <= tot; i ++) ver[i] = Next[i] = 0;
    tot = 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}