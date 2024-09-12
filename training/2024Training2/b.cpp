#include <bits/stdc++.h>

#define int long long

using namespace std;
const int maxn = 15, INF = 1e18;
int n, m, K, atk[35][35][1 << 12], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool vis[35][35][1 << 12];
int dis[35][35][1 << 12];
struct node{
    int x, y, a, b, c;
    node(int x = 0, int y = 0, int a = 0, int b = 0, int c = 0) : x(x), y(y), a(a), b(b), c(c) {}
}mon[maxn];
struct state{
    int x, y, sta, money;
    state(int x = 0, int y = 0, int sta = 0, int money = 0) : x(x), y(y), sta(sta), money(money) {}
    bool operator <(const state other) const {
        return money < other.money;
    }
};
int manha(int x2, int y2, int x3, int y3) {
    return abs(x2 - x3) + abs(y2 - y3);
}
void solve() {
    vector<int> id[35][35];
    int lim = 0;
    scanf("%lld%lld%lld%lld", &n, &m, &K, &lim);
    for(int i = 0; i < K; i ++) {
        int x, y, a, b, c;
        scanf("%lld%lld%lld%lld%lld", &x, &y, &a, &b, &c);
        mon[i] = node(x, y, a, b, c);
        id[x][y].push_back(i);
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) 
            for(int k = 0; k < (1 << K); k ++) atk[i][j][k] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            for(int k = 0; k < (1 << K); k ++) {
                for(int l = 0; l < K; l ++) {
                    if((k >> l) & 1);
                    else if(manha(i, j, mon[l].x, mon[l].y) <= mon[l].c) {
                        atk[i][j][k] += mon[l].b;
                    }
                }
            }
        }
    }
    int X, Y;
    scanf("%lld%lld", &X, &Y);
	if(id[X][Y].size()) {
		printf("0\n");
		return;
	}
    priority_queue<state> q;
    q.push(state(X, Y, 0, 0));
    int ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            for(int k = 0; k < (1 << K); k ++)
                dis[i][j][k] = -INF, vis[i][j][k] = 0;
    dis[X][Y][0] = 0;
    while(q.size()) {
        auto u = q.top(); q.pop();
        if(vis[u.x][u.y][u.sta]) continue;
        vis[u.x][u.y][u.sta] = 1;
        for(int j = 1; j <= lim; j ++) {
            for(int i = 0; i < 4; i ++) {
                int ex = u.x + dx[i] * j, ey = u.y + dy[i] * j, sta = u.sta;
                if(ex < 1 || ey < 1 || ex > n || ey > m) continue;
                bool flag = 0;
                for(auto momo : id[ex][ey]) {
                    if((u.sta >> momo) & 1) continue;
                    flag = 1; break;
                }
                if(flag) continue;
                int lx = min(u.x, ex), rx = max(u.x, ex), ly = min(u.y, ey), ry = max(u.y, ey), val = 0;
                if(lx < rx) {
                    for(int it = lx; it <= rx; ++ it) {
                        for(auto momo : id[it][ey]){
                            if(sta&(1 << momo));
                            else {
                                val += mon[momo].a;
                                sta |= (1 << momo);
                            }
                        }
                    }
                }
                else {
                    for(int it = ly; it <= ry; ++ it) {
                        for(auto momo : id[ex][it]) {
                            if(sta&(1 << momo));
                            else {
                                val += mon[momo].a;
                                sta |= (1 << momo);
                            }
                        }
                    }
                }
                if(dis[u.x][u.y][u.sta] - atk[ex][ey][sta] + val > dis[ex][ey][sta]) {
                    dis[ex][ey][sta] = dis[u.x][u.y][u.sta] - atk[ex][ey][sta] + val;
                    ans = max(ans, dis[ex][ey][sta]);
                    q.push(state(ex, ey, sta, dis[ex][ey][sta]));
                }
            }
        }
    }
    printf("%lld\n", ans);
}
signed main() {
    int T;
    scanf("%lld", &T);
    while(T --) solve();
    return 0;
}
