#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, INF = 1e9 + 7;
int n, p[maxn], f[maxn];
vector<int> g[maxn];
void dfs(int x) {
    int mini = INF;
    for(auto y : g[x]) {
        dfs(y);
        mini = min(mini, f[y]);
    }
    if(mini == INF) f[x] = 1;
    else f[x] = mini + 1;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) g[i].clear();
    for(int i = 1; i <= n; i ++) f[i] = 0;
    for(int i = 2; i <= n; i ++) cin >> p[i], g[p[i]].push_back(i);
    dfs(1);
    f[1] --;
    int ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}