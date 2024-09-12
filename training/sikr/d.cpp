#include <bits/stdc++.h>

using namespace std;
const int maxn = 5;
int n, m, a[maxn][maxn], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, Ans;
int bfs(int x[maxn][maxn], int i, int j, int k) {
    queue<pair<int, int>> q;
    int vis[maxn][maxn] = {};
    q.push(make_pair(i, j));
    vis[i][j] = 1;
    int cnt = 1;
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        for(int l = 0; l < 4; l ++) {
            int sx = it.first + dx[l], sy = it.second + dy[l];
            if(sx < 0 or sy < 0 or sx >= n or sy >= m or x[sx][sy] != k or vis[sx][sy]) continue;
            q.push(make_pair(sx, sy));
            vis[sx][sy] = 1;
            cnt ++;
        }
    }
    return cnt;
}
int ok(int x[maxn][maxn], int i, int j) {
    return bfs(x, i, j, x[i][j]);
}
void print(int x[maxn][maxn]) {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void dfs(int x[maxn][maxn], int ans) {
    Ans = max(ans, Ans);
    int b[maxn][maxn];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(x[i][j] == 0) continue;
            int g = ok(x, i, j);
            if(g >= 3) {
                queue<pair<int, int>> q;
                int vis[maxn][maxn] = {};
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                int cnt = 1;
                while(!q.empty()) {
                    auto it = q.front();
                    q.pop();
                    for(int l = 0; l < 4; l ++) {
                        int sx = it.first + dx[l], sy = it.second + dy[l];
                        if(sx < 0 or sy < 0 or sx >= n or sy >= m or x[sx][sy] != x[i][j] or vis[sx][sy]) continue;
                        q.push(make_pair(sx, sy));
                        vis[sx][sy] = 1;
                        cnt ++;
                    }
                }
                for(int i = 0; i < n; i ++)
                    for(int j = 0; j < m; j ++) {
                        if(vis[i][j]) b[i][j] = 0;
                        else b[i][j] = x[i][j];
                    }
                // cout<<cnt<<" "<<g<<endl;
                for(int k = 0; k < m; k ++) {
                    for(int l = n - 1; l >= 0; l --) {
                        if(b[l][k]) continue;
                        for(int p = l - 1; p >= 0; p --) {
                            if(b[p][k]) {
                                b[l][k] = b[p][k];
                                b[p][k] = 0;
                                break;
                            }
                        }
                    }
                }
                // print(b);
                // print(x);
                dfs(b, ans + cnt);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> a[i][j];
    dfs(a, 0);
    cout<<Ans;
    return 0;
}