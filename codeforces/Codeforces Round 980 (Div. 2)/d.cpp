#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e5 + 5;
int a[maxn], b[maxn], n;
long long f[maxn], sum[maxn];
bool vis[maxn];
void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    for(int i = 1; i <= n; i ++) f[i] = 1e18, vis[i] = 0;
    f[1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        if(f[b[u]] > f[u] + a[u]) {
            f[b[u]] = f[u] + a[u];
            q.push(make_pair(f[b[u]], b[u]));
        }
        if(u > 1 && f[u - 1] > f[u]) {
            f[u - 1] = f[u];
            q.push(make_pair(f[u - 1], u - 1));
        }
    }
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    dijkstra();
    long long ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, sum[i] - f[i]);
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}