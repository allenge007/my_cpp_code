#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 6;
int n;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot, siz[maxn], cnt[maxn];
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
void dfs(int x, int fa) {
    siz[x] = 1;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        dfs(ver[i], x);
        siz[x] += siz[ver[i]];
    }
    cnt[siz[x]] ++;
}
bool ok(int x) {
    if(n % (x + 1)) return 0;
    int ans = 0;
    for(int i = n/(x + 1); i <= n; i += n/(x + 1)) ans += cnt[i];
    return ans == x + 1;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    for(int i = 1; i < n; i ++) {
        if(ok(i)) printf("%d ", i);
    }
    return 0;
}