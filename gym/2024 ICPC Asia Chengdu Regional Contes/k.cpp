#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e7 + 5, maxn = 305, inf = 1e12 + 7, INF = 1e12 + 7;
int cur[N], n, a[maxn], s, t, flow, cost, dist[N], inq[N], head[N], cnt;
struct edge {
    int to, cap, flow, dis, nxt;
}edges[N];
bool SPFA() { 
    queue<int> q;
    for (int i = 1; i <= t; i++) {
        dist[i] = inf;
        inq[i] = 0;
    }
    q.push(s);
    dist[s] = 0;
    inq[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        inq[x] = 0;
        cur[x] = head[x];
        for (int i = head[x]; ~i; i = edges[i].nxt) {
            edge &e = edges[i];
            if (e.flow < e.cap && dist[e.to] > dist[x] + e.dis) {
                dist[e.to] = dist[x] + e.dis;
                if (!inq[e.to])
                    inq[e.to] = 1, q.push(e.to);
            }
        }
    }
    return dist[t] != INF;
}

bool vis[N];

int dfs(int x, int a) {
    if (x == t || a == 0)
        return a;
    vis[x] = 1;
    int flow = 0, f;
    for (int &i = cur[x]; ~i; i = edges[i].nxt) {
        edge &e = edges[i];
        if (vis[e.to])
            continue;
        if (dist[e.to] == dist[x] + e.dis && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[i ^ 1].flow -= f;
            cost += e.dis * f;
            flow += f;
            a -= f;
            if (a == 0)
                break;
        }
    }
    vis[x] = 0;
    return flow;
}

pair<int, int> mincostmaxflow(int _s, int _t) {
    cost = flow = 0;
    s = _s, t = _t;
    while (SPFA())
        flow += dfs(s, INF);
    return make_pair(flow, cost);
}
set<int> S, fac[maxn];
map<int, int> val;
int id;
int calc(int x) {
    int ans = 0;
    for(int i = 2; i * i <= x; i ++) {
        if(x % i == 0) {
            while(x % i == 0) x /= i, ans ++;
        }
    }
    if(x > 1) ans ++;
    return ans;
}
void add(int u, int v, int cap, int dis) {
    edges[cnt] = {v, cap, 0, dis, head[u]};
    head[u] = cnt ++;
    edges[cnt] = {u, 0, 0, -dis, head[v]};
    head[v] = cnt ++;
}
signed main() {
    ios ::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j * j <= a[i]; j ++) {
            if(a[i] % j == 0) {
                fac[i].insert(j);
                fac[i].insert(a[i] / j);
            }
        }
        int tmp = 0;
        for(auto x : fac[i]) {
            tmp ++;
            if(tmp > 2 * n) break;
            S.insert(x);
        }
        S.insert(a[i]);
    }
    for(auto it : S) {
        val[it] = ++ id;
    }
    int sum = 0;
    for(int i = 1; i <= n; i ++) sum += calc(a[i]);
    memset(head, -1, sizeof(head));
    cnt = 0;
    for(int i = 1; i <= n; i ++) {
        int tmp = 0;
        for(auto it : fac[i]) {
            if(it == a[i]) continue;
            tmp ++;
            if(tmp > 2 * n) break;
            add(val[a[i]], val[it], 1, 0);
        }
    }
    s = id + 1, t = id + 2;
    for(int i = 1; i <= n; i ++) add(s, val[a[i]], 1, 0);
    for(auto it : S) add(val[it], t, 1, calc(it));
    pair<int, int> ans = mincostmaxflow(s, t);
    cout << sum - ans.second << endl;
    return 0;
}