#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1000000;
int a[N], c[N], f[N][3];
vector<int> G[N];

void dfs(int u, int p) {
    int son = 0;
    for(auto v : G[u]) {
        if(v == p) continue;
        son ++;
        dfs(v, u);
    }
    if(!son) {
        if(!c[u]) return void(f[u][0] = 1);
        f[u][0] = 1, f[u][1] = 0;
        return ;
    }
    bool flag2 = c[u];
    int flag = 0;
    int ans = 0;
    for(auto v : G[u]) {
        if(v == p) continue;
        if(f[v][1] == INF && f[v][2] == INF) flag += 1, ans += f[v][0];
        else if(f[v][2] <= f[v][1] + 1 && !flag2) ans += f[v][2], flag2 = 1;
        else ans += f[v][1];
    }
    if(!flag2) f[u][0] = ans + flag, f[u][1] = f[u][2] = INF;
    else {
        if(flag) f[u][2] = ans + flag;
        else f[u][1] = ans, f[u][2] = ans + 1;
    }
}


inline void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) {
        c[i] = 0, G[i].clear();
        for(int j = 0; j < 3; ++j)
            f[i][j] = INF;
    }
    for(int i = 1; i <= m; ++i) c[a[i]] = 1;
    for(int i = 2; i <= n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }

    dfs(1, 0);

    printf("==%d\n", min(f[1][1], f[1][2]));
}

int main() {
    int cas;
    scanf("%d", &cas);
    while(cas--) solve();
    return 0;
}
/*
1
12 3
2 3 12
1 2
1 3
2 4
3 5
3 6
3 7
7 8
7 9
8 10
9 11
9 12
*/