#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char str[maxn][maxn];
int n, m, a[maxn][maxn], vis[maxn][maxn][25], dis[maxn][maxn][25];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main() {
    int sx, sy, fx, fy;
    scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &fx, &fy);
    sx --, sy --, fx --, fy --;
    for(int i = 0; i < n; i ++)
        scanf("%s", str[i]);
    for(int i = n - 1; i >= 0; i --)
        for(int j = m - 1; j >= 0; j --) {
            if(str[i][j] == '#') continue;
            if(i == n - 1 or j == m - 1) a[i][j] = 1;
            else {
                a[i][j] = min(a[i + 1][j], min(a[i][j + 1], a[i + 1][j + 1])) + 1;
            }
        }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            for(int k = 1; k <= 20; k ++)
                vis[i][j][k] = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 1});
    dis[sx][sy][1] = 0;
    vis[sx][sy][1] = 1;
    if(str[sx][sy] == '#' or str[fx][fy] == '#') return printf("0"), 0;
    while(!q.empty()) {
        auto it = q.front();
        int nx = it.first.first, ny = it.first.second, l = it.second;
        q.pop();
        int l2 = l - 1;
        if(l2) {
            if(!vis[nx][ny][l2]) {
                dis[nx][ny][l2] = dis[nx][ny][l] + 1;
                vis[nx][ny][l2] = 1;
                q.push({{nx, ny}, l2});
            }
        }
        l2 = l + 1;
        if(l2 <= min(a[nx][ny], 20)) {
            if(!vis[nx][ny][l2]) {
                dis[nx][ny][l2] = dis[nx][ny][l] + 1;
                vis[nx][ny][l2] = 1;
                q.push({{nx, ny}, l2});
            }
        }
        for(int i = 0; i < 4; i ++) {
            int ex = nx + dx[i] * l, ey = ny + dy[i] * l;
            if(ex < 0 or ey < 0 or ex >= n or ey >= m or vis[ex][ey][l] or a[ex][ey] < l or str[ex][ey] == '#') continue;
            dis[ex][ey][l] = dis[nx][ny][l] + 1;
            vis[ex][ey][l] = 1;
            q.push({{ex, ey}, l});
        }
    }
    printf("%d\n", dis[fx][fy][1]);
    return 0;
}

/*
5 8
1 1 5 8
........
........
.....###
........
.....#..
*/