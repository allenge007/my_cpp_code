#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, INF = 1e9 + 7;
const long long mod = 1e9 + 7;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int n, m, d[maxn];
long long f[maxn];
void bfs() {
    for(int i = 1; i <= n; i ++) d[i] = INF;
    f[1] = 1, d[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if(d[y] < d[x] + 1) continue;
            if(d[y] == d[x] + 1) f[y] += f[x], f[y] %= mod;
            else d[y] = d[x] + 1, f[y] = f[x], q.push(y);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    bfs();
    printf("%lld", f[n]);
    return 0;
}