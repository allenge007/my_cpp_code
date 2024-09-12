#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e3 + 5;
int head[maxn], ver[maxn << 1], Next[maxn << 1], edge[maxn << 1], tot;
void add(int x, int y, int z) {
    ver[++ tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}
int n, m, in[maxn], dis[maxn];
bool vis[maxn];
int spfa() {
    queue<int> q;
    for(int i = 1; i <= n; i ++) dis[i] = 1;
    q.push(n + 1);
    vis[n + 1] = 1;
    in[n + 1] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for(int i = head[u]; i; i = Next[i]) {
            if(dis[u] + edge[i] < dis[ver[i]]) {
                dis[ver[i]] = dis[u] + edge[i];
                if(!vis[ver[i]]) {
                    vis[ver[i]] = 1, in[ver[i]] ++;
                    if(in[ver[i]] >= n + 1) return 0;
                    q.push(ver[i]);
                }
            }
        }
    }
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(y, x, z);
    }
    for(int i = 1; i <= n; i ++) add(n + 1, i, 0);
    if(!spfa()) return printf("NO\n"), 0;
    for(int i = 1; i <= n; i ++) printf("%d ", dis[i]);
    return 0;
}