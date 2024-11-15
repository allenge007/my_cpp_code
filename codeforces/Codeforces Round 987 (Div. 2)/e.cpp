#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int p[maxn], n, deg[maxn], dep[maxn];
vector<int> g[maxn];
void dfs(int x) {
    for(auto v : g[x]) {
        dfs(v);
    }
    int maxi = 0;
    if(deg[x] <= 2) {
        for(auto v : g[x]) {
            maxi = max(maxi, dep[v]);
        }
        return dep[x] = maxi + 1, void();
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto v : g[x]) {
        q.push(dep[v]);
    }
    while(q.size() > 2) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        q.push(max(a, b) + 1);
    }
    while(!q.empty()) {
        maxi = max(maxi, q.top());
        q.pop();
    }
    dep[x] = maxi + 1;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) g[i].clear(), dep[i] = 0;
    for(int i = 2; i <= n; i ++) cin >> p[i], deg[p[i]] ++, g[p[i]].push_back(i);
    dfs(1);
    cout << dep[1] - 1 << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}