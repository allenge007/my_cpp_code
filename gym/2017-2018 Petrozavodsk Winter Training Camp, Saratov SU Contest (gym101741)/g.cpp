#include <bits/stdc++.h>

using namespace std;
const int maxm = 2005, maxn = 1005, INF = 1e5 + 7;
int head[maxn], ver[maxm], Next[maxm], edge[maxm], tot;
void add(int x, int y, int z) {
    ver[++ tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}
int n, m, a[maxm], b[maxm], d[maxm], o[maxn], dis[maxn], in[maxn];
bool vis[maxn];
void read(int &w) {
    w = 0;
    int f = 1; char ch = getchar();
    while(ch < '0' || ch  > '9') {
        if(ch == '?') {
            w = INF, return ;
        }
        else if(ch == '-') f = -f;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    w *= f;
}
bool spfa() {
    queue<int> q;
    q.push(n + 1);
    dis[n + 1] = 0, vis[n + 1] = 1, in[n + 1] = 1;
    for(int i = 1; i <= n; i ++) dis[i] = INF;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = Next[i]) {
            if(dis[ver[i]] > dis[u] + edge[i]) {
                dis[ver[i]] = dis[u] + edge[i];
                if(!vis[ver[i]]) {
                    vis[ver[i]] = 1;
                    in[ver[i]] ++, q.push(ver[i]);
                    if(in[ver[i]] >= n + 1) return 0;
                }
            }
        }
    }
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for(int i = 1; i <= n; i ++) {
        read(o[i]);
    }
    int l = 0, r = 1e5 + 5;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n");
    for(int i = 1; i <= n; i ++) {
        if(o[i] != INF) [
            add(n + 1, i, o[i]);
            add(i, n + 1, -o[i]);
        ]
    }

    if(!spfa()) return printf("")
    return 0;
}