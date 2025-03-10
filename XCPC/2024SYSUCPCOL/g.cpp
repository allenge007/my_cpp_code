#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5, maxm = 2e5 + 5;
int n, m, a[maxn], up[maxn], down[maxn];
bool sta[maxn], flag;
struct node{
    int to, id, rev;
};
vector<node> g[maxn];
void add(int x, int y, int id, int rev) {
    g[x].push_back((node){y, id, rev});
}
void dfs(int x, int fa) {
    vector<int> que;
    for(auto [v, id, rev] : g[x]) {
        if(v == fa) continue;
        dfs(v, x);
    }
    int maxd = 0, maxu = 0;
    for(auto [v, id, rev] : g[x]) {
        if(v == fa) continue;
        if(up[v]) {
            maxu = max(maxu, up[v] - 1);
            sta[id] = rev ^ 1;
        } else {
            maxd = max(maxd, down[v] + 1);
            sta[id] = rev;
        }
    }
    if(a[x] > maxd) up[x] = a[x];
    if(maxu > maxd) up[x] = max(maxu, up[x]);
    down[x] = maxd;
    if(x == 1 && maxu > maxd) {
        flag = 1;
        return ;
    }
}
bool vis[maxn], inbfs[maxn];
int top, fid;
node st[maxn];
vector<int> cir;
void dfs2(int x, int fa) {
    vis[x] = 1;
    for(auto [v, id, rev] : g[x]) {
        if(cir.size()) return ;
        if(v == fa) continue;
        if(vis[v]) {
            while(st[top].to != v) {
                cir.push_back(st[top].to);
                sta[st[top].id] = st[top].rev;
                top --;
            }
            sta[id] = rev;
            cir.push_back(v);
            return ;
        } else {
            st[++ top] = (node){v, id, rev};
            dfs2(v, x);
            top --;
        }
    }
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        add(x, y, i, 0), add(y, x, i, 1);
    }
    if(m == n - 1) {
        dfs(1, 0);
        if(flag || up[1]) return cout << -1 << endl, 0;
        for(int i = 1; i <= m; i ++) cout << sta[i];
        cout << endl;
        return 0;
    }
    dfs2(1, 0);
    queue<int> q;
    for(auto x : cir) inbfs[x] = 1, q.push(x);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto [v, id, rev] : g[x]) {
            if(inbfs[v]) continue;
            sta[id] = rev ^ 1;
            q.push(v);
            inbfs[v] = 1;
        }
    }
    for(int i = 1; i <= m; i ++) cout << sta[i];
    return 0;
}