#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 100005;
const long long INF = 1e17;
int head[maxn], ver[maxn << 1], Next[maxn << 1], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int a[maxn], n, p;
long long siz[maxn], ans, cnt;
void dfs(int x, int fa) {
    siz[x] = a[x];
    long long maxi = 0;
    for(int i = head[x]; i; i = Next[i]) {
        if(ver[i] == fa) continue;
        dfs(ver[i], x);
        if(siz[ver[i]] > maxi) {
            maxi = siz[ver[i]];
        }
        siz[x] += siz[ver[i]];
    }
    if(max(maxi, cnt - siz[x]) < ans) {
        ans = max(maxi, cnt - siz[x]);
        p = x;
    }
}
signed main() {
    ans = INF;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]), cnt += a[i];
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 1);
    printf("%lld\n", p);
    return 0;
}