#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e4 + 5, INF = 2e10 + 7;
int head[maxn], Next[maxn << 1], edge[maxn << 1], pri[maxn << 1],  ver[maxn << 1], tot;
void add(int x, int y, int w, int p) {
    ver[++ tot] = y, edge[tot] = w, pri[tot] = p, Next[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, pri[tot] = -p, Next[tot] = head[y], head[y] = tot;
}
int n, m, a[maxn], V[maxn], S, T, cost, dis[maxn], vis[maxn], cur[maxn];
struct node{
    int x, y, w;
    node(int x = 0, int y = 0, int w = 0) : x(x), y(y), w(w) {};
}qury[maxn];
bool spfa() {
    queue<int> q;
    q.push(S);
    for(int i = 1; i <= T; i ++) vis[i] =  0, dis[i] = INF;
    vis[S] = 1, dis[S] = 0;
    while(!q.empty()) {
         int x = q.front();
         q.pop();
         vis[x] = 0, cur[x] = head[x];
         for(int i = head[x]; i; i = Next[i]) {
            if(edge[i] > 0 && dis[ver[i]] > dis[x] + pri[i]) {
                dis[ver[i]] = dis[x] + pri[i];
                if(!vis[ver[i]]) vis[ver[i]] = 1, q.push(ver[i]);
            }
         }
    }
    return dis[T] != INF;
}
bool vis2[maxn];
int dfs(int x, int a) {
    if(x == T || a == 0) return a;
    vis2[x] = 1;
    int flow = 0, f;
    for(int &i = cur[x]; i; i = Next[i]) {
        if(vis2[ver[i]]) continue;
        if(edge[i] && dis[ver[i]] == dis[x] + pri[i] && (f = dfs(ver[i], min(a, edge[i])))) {
            edge[i] -= f;
            edge[i ^ 1] += f;
            cost += pri[i] * f;
            flow += f, a -= f;
            if(!a) break;
        }
    }
    vis2[x] = 0;
    return flow;
}
signed main() {
    int lim = 0;
    tot = 1;
    scanf("%lld%lld", &n, &m);
    S = n + m + 1, T = n + m + 2;
    for(int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        a[i] = x, V[i] = y;
    }
    int maxi = V[1];
    for(int i = 1; i <= m; i ++) {
        int x, y, w;
        scanf("%lld%lld%lld", &x, &y, &w);
        qury[i] = node(x, y, w);
        if(x == 1 || y == 1) maxi += w;
    }
    maxi = min(maxi, a[1]);
    // cout << maxi << "fuck\n";
    if(maxi == 0) return printf("NO\n"), 0;
    add(S, 1, maxi - V[1], 0);
    for(int i = 2; i <= n; i ++){
        if(maxi - 1 < V[i]) return printf("NO\n"), 0;
        add(S, i, min(maxi - 1 - V[i], a[i] - V[i]), 1);
    }
    for(int i = 1; i <= m; i ++) {
        int x = qury[i].x, y = qury[i].y, w = qury[i].w;
        add(x, n + i, w, 0);
        add(y, n + i, w, 0);
        add(n + i, T, w, 0);
        lim += w;
    }
    int flow = cost = 0;
    while(spfa()) flow += dfs(S, INF);
    // cout << lim << " " << flow << " " << cost << endl;
    if(flow == lim) printf("YES\n");
    else printf("NO\n");
    return 0;
}