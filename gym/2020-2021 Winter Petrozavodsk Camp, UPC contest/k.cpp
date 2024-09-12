#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, M = 2e6 + 5;
int n, m, ans;
int tot = 1, hd[N];

struct edge
{
    int to, nt;
} e[M << 1];

void add(int u, int v) { e[++tot].to = v, e[tot].nt = hd[u], hd[u] = tot; }

void uadd(int u, int v) { add(u, v), add(v, u); }

bool bz[M << 1];
int bcc_cnt, dfn[N], low[N], vis_bcc[N];
vector<vector<int>> bcc;

void tarjan(int x, int in)
{
    dfn[x] = low[x] = ++bcc_cnt;
    for (int i = hd[x]; i; i = e[i].nt)
    {
        int v = e[i].to;
        if (dfn[v] == 0)
        {
            tarjan(v, i);
            if (dfn[x] < low[v])
                bz[i] = bz[i ^ 1] = 1;
            low[x] = min(low[x], low[v]);
        }
        else if (i != (in ^ 1))
            low[x] = min(low[x], dfn[v]);
    }
}

void dfs(int x, int id)
{
    vis_bcc[x] = id;
    for (int i = hd[x]; i; i = e[i].nt)
    {
        int v = e[i].to;
        if (vis_bcc[v] || bz[i])
            continue;
        dfs(v, id);
    }
}

bool vis[N], vis2[N];
vector<int> g[N];
void Add(int x, int y){
    // cout << x << " -> " << y << endl;
    g[x].push_back(y), g[y].push_back(x);
}

void build(int x, int id) {
    vis[x] = 1;
    for(int i = hd[x]; i; i = e[i].nt) {
        int v = e[i].to;
        if(vis[v]) continue;
        if(bz[i]) {
            Add(id, vis_bcc[v]);
            continue;
        }
        
        build(v, id);
    }
}

int dep[N], cnum;
void calc(int x, int fa) {
    vis2[x] = 1;
    int p1 = 0, p2 = 0;
    for(auto y : g[x]) {
        if(y == fa || vis2[y]) continue;
        calc(y, x);
        if(dep[y] >= dep[p1]) p2 = p1, p1 = y;
        else if(dep[y] >= dep[p2]) p2 = y;
    }
    // cout << x << " " << p1 << " " << p2 << endl;
    if(p1) dep[x] = dep[p1] + 1;
    if(p2) cnum = max(cnum, dep[p1] + dep[p2] + 2);
    else if(p1) cnum = max(cnum, dep[p1] + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        if (u == v)
            continue;
        uadd(u + 1, v + 1);
    }
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            tarjan(i, 0);
    for (int i = 1; i <= n; i++)
        if (vis_bcc[i] == 0)
        {
            dfs(i, ++ans);
        }
    // cout << ans << endl;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) build(i, vis_bcc[i]);
    }
    int lenth = 0;
    for(int i = 1; i <= ans; i ++) {
        if(!vis2[i]) {
            cnum = 0;
            calc(i, 0);
            lenth += cnum + 1;
        }
    }
    printf("%d\n", lenth - 1);
    return 0;
}
/*
6 6
0 1
1 2
2 0
0 3
1 4
2 5
*/