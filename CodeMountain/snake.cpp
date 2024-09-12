#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int a[maxn][maxn], n, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void dfs(int x, int y, int t, int dir) {
    a[x][y] = t;
    int ex = x + dx[dir], ey = y + dy[dir];
    if(a[ex][ey] or ex > n or ey > n or ex < 1 or ey < 1) {
        for(int j = 0; j < 4; j ++) {
            int sx = x + dx[j], sy = y + dy[j];
            if(!a[sx][sy] and sx >= 1 and sx <= n and sy >= 1 and sy <= n) {
                dfs(sx, sy, t + 1, j);
                return ;
            }
        }
    }
    else dfs(ex, ey, t + 1, dir);
}
int main() {
    scanf("%d", &n);
    dfs(1, 1, 1, 0);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++)
            printf("    %d", a[i][j]);
        printf("\n");
    }
    return 0;
}