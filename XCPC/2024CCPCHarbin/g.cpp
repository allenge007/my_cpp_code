#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, maxm = 5e5 + 5;
int head[maxn], Next[maxm << 1], ver[maxm << 1], tot;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
int n, m, k, a[maxn], ord[maxn], num;
bool ban[maxn], vis[maxn];
vector<int> ans[maxn];
void bfs(int x) {
    vis[x] = 1;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ord[++ num] = u;
        for(int i = head[u]; i; i = Next[i]) {
            int v = ver[i];
            if(!vis[v]) {
                vis[v] = 1;
                ans[u].push_back(v);
                if(!ban[v]) q.push(v);
            }
        }
    }
}
int main() {
    ios :: sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i ++) cin >> a[i], ban[a[i]] = 1;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    for(int i = 1; i <= n; i ++) {
        if(!ban[i]) {
            bfs(i);
            break;
        }
    }
    for(int i = 1; i <= n; i ++) if(!vis[i]) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(ans[i].size()) cnt ++;
    cout << cnt << endl;
    for(int i = 1; i <= num; i ++) {
        if(ans[ord[i]].size()) {
            cout << ord[i] << " " << ans[ord[i]].size() << " ";
            for(auto j : ans[ord[i]]) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}