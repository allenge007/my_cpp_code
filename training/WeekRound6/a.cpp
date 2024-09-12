#include <bits/stdc++.h>

using namespace std;
const int maxn = 65;
char str[maxn][maxn];
int vis[maxn][maxn], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, dis[maxn][maxn][maxn][maxn], n;
bool v[maxn][maxn][maxn][maxn];
void dfs(int x, int y, int flag) {
    vis[x][y] = flag;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 or ny < 0 or nx >= n or ny >= n or vis[nx][ny] or str[nx][ny] == '#') continue;
        dfs(nx, ny, flag);
    }
}
struct node{
    int a, b, c, d;
};
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        scanf("%s", str[i]);
    int cnt = 0;
    pair<int, int> p1 = {0, 0}, p2 = {0, 0};
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++){
            if(str[i][j] == 'P' && !vis[i][j]) {
                dfs(i, j, ++ cnt);
            }
            if(str[i][j] == 'P') {
                if(p1 == make_pair(0, 0)) p1 = {i, j};
                else p2 = {i, j};
            }
        }
    if(vis[p1.first][p1.second] != vis[p2.first][p2.second]) return printf("-1\n"), 0;
    memset(dis, 63, sizeof dis);
    queue<node> q;
    q.push({p1.first, p1.second, p2.first, p2.second});
    v[p1.first][p1.second][p2.first][p2.second] = 1;
    dis[p1.first][p1.second][p2.first][p2.second] = 0;
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int nx1 = top.a + dx[i], ny1 = top.b + dy[i];
            int nx2 = top.c + dx[i], ny2 = top.d + dy[i];
            if(nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || str[nx1][ny1] == '#') nx1 -= dx[i], ny1 -= dy[i];
            if(nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || str[nx2][ny2] == '#') nx2 -= dx[i], ny2 -= dy[i];
            // cout << top.a << " " << top.b << " " << nx1 << " " << ny1 << endl;
            // cout << top.c << " " << top.d << " " << nx2 << " " << ny2 << endl;
            // cout <<  "---------------\n";
            if(dis[nx1][ny1][nx2][ny2] > dis[top.a][top.b][top.c][top.d] + 1){
                dis[nx1][ny1][nx2][ny2] = dis[top.a][top.b][top.c][top.d] + 1;
                if(!v[nx1][ny1][nx2][ny2]) {
                    v[nx1][ny1][nx2][ny2] = 1;
                    q.push({nx1, ny1, nx2, ny2});
                }
            }
        }
    }
    int ans = 1e9 + 7;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) {
            ans = min(ans, dis[i][j][i][j]);
            // cout << dis[i][j][i][j] << " ";
        }
        // cout << endl;
    }
        
            
    return printf("%d\n", ans), 0;
}