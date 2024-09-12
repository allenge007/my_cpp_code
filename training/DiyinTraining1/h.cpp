#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1005;
int h[maxn][maxn], n, m, y, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool vis[maxn][maxn];
struct node{
    int x, y, h;
    node(int x, int y, int h) : x(x), y(y), h(h) {}
    bool operator <(const node oth) const{
        return h > oth.h;
    }
};
priority_queue<node> q;
int main() {
    n = read(), m = read(), y = read();
    long long ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            h[i][j] = read();
            if(i == 1 || i == n || j == 1 || j == m) q.push(node(i, j, h[i][j])), vis[i][j] = 1;
        }
    ans = n * m;
    for(int i = 1; i <= y; i ++) {
        while(!q.empty() && q.top().h <= i) {
            auto it = q.top();
            -- ans;
            q.pop();
            for(int i = 0; i < 4; i ++) {
                int xx = it.x + dx[i], yy = it.y + dy[i];
                if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) continue;
                q.push(node(xx, yy, h[xx][yy]));
                vis[xx][yy] = 1;
            }
            // cout << it.h << " ";
        }
        // cout << endl;
        printf("%lld\n", ans);
    }
    return 0;
}