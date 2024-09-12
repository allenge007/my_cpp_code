#include <bits/stdc++.h>

using namespace std;
#define sec second
#define fir first
const int maxn = 15;
int n, K, m, c[maxn], dis[1025][1025];
bool vis[1025][1025];
vector<int> pos[maxn];
void bfs() {
    memset(dis, -1, sizeof dis);
    queue<pair<int, int>> q;
    int ss = 0;
    for(int i = 0; i < n; i ++) if(c[i] == 1) ss |= (1 << i);
    q.push({ss, 0});
    vis[ss][0] = 1, dis[ss][0] = 0;
    while(!q.empty()) {
        auto u = q.front();
        int no = 0;
        q.pop();
        for(int i = 0; i < m; i ++) {
            if(!vis[u.fir][u.sec ^ (1 << i)]) {
                vis[u.fir][u.sec ^ (1 << i)] = 1;
                dis[u.fir][u.sec ^ (1 << i)] = dis[u.fir][u.sec] + 1;
                q.push({u.fir, u.sec ^ (1 << i)});
                if(u.fir == (1 << n) - 1 && (u.sec ^ (1 << i)) == 0) return ;
            }
            if((u.sec >> i) & 1) {
                for(auto it : pos[i]) no |= (1 << it);
            }
        }
        for(int i = 1; i <= K; i ++) {
            int sta = u.fir;
            for(int j = 0; j < n; j ++) {
                if((no >> j) & 1) continue;
                if(c[j] == i) sta |= (1 << j);
                else if(sta & (1 << j)) sta ^= (1 << j);
            }
            if(!vis[sta][u.sec]) {
                vis[sta][u.sec] = 1;
                dis[sta][u.sec] = dis[u.fir][u.sec] + 1;
                q.push({sta, u.sec});
                if(sta == (1 << n) - 1 && u.sec == 0) return ;
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &K, &m);
    for(int i = 0; i < n; i ++) scanf("%d", &c[i]);
    for(int i = 0; i < m; i ++) {
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; j ++) {
            int x;
            scanf("%d", &x);
            pos[i].push_back(x - 1);
        }
    }
    bfs();
    printf("%d\n", dis[(1 << n) - 1][0]);
    return 0;
}