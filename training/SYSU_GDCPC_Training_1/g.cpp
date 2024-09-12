#include <bits/stdc++.h>

using namespace std;
const int maxn = 20;
int a[maxn][maxn], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool vis[maxn][maxn];
int dfs(int x, int y, int k) {
    vis[x][y] = 1;
    int cnt = 0;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 or ny < 1 or nx > 19 or ny > 19 or vis[nx][ny] or a[nx][ny] != k) continue;
        cnt += dfs(nx, ny, k);
    }
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 or ny < 1 or nx > 19 or ny > 19) continue;
        cnt += (a[nx][ny] == 0);
    }
    return cnt;
}
int Remove(int x, int y, int k) {
    a[x][y] = 0;
    int cnt = 1;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 or ny < 1 or nx > 19 or ny > 19 or a[nx][ny] != k) continue;
        cnt += Remove(nx, ny, k);
    }
    return cnt;
}
int remove(int x) {
    memset(vis, 0, sizeof vis);
    int cnt = 0, ans = 0;
    for(int i = 1; i <= 19; i ++) {
        for(int j = 1; j <= 19; j ++) {
            if(a[i][j] == x and !vis[i][j]) {
                cnt = dfs(i, j, x);
                if(cnt == 0) {
                    ans += Remove(i, j, x);
                }
            }
        }
    }
    return ans;
}
void print() {
    for(int i = 1; i <= 4; i ++) {
        for(int j = 1; j <= 4; j ++)
            printf("%d", a[i][j]);
        printf("\n");
    }
}
int main() {
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 2 - i%2;
        int cnt1 = remove(i % 2 + 1);
        int cnt2 = remove(2 - i % 2);
        // print();
        if(i%2 == 1) printf("%d %d\n", cnt2, cnt1);
        else printf("%d %d\n", cnt1, cnt2);
    }
    return 0;
}