#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int num[2][55][55], f[2][55][55][15][15][15], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char str[55][55];
void solve() {
    int n, m, K, hp, ans = 0;
    scanf("%d%d%d%d", &n, &m, &K, &hp);
    for(int i = 1; i <= n; i ++) scanf("%s", str[i] + 1);
    int X = 0, Y = 0, DX = 0, DY = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) {
            if(str[i][j] != '#') num[0][i][j] = 1;
            else if(str[i][j] == '#') num[0][i][j] = 0;
            if(str[i][j] == 'P') X = i, Y = j;
            else if(str[i][j] == 'E') DX = i, DY = j;
        }
    DX = DX - X, DY = DY - Y;
    int tt = 1;
    for(int k = 1; k <= K; k ++) {
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                num[tt][i][j] = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++) {
                if(!num[tt ^ 1][i][j]) continue;
                if(str[i][j] == '#') continue;
                for(int d = 0; d < 4; d ++) {
                    int ex = i + dx[d], ey = j + dy[d];
                    if(ex < 1 || ey < 1 || ex > n || ey > n || str[ex][ey] == '#') continue;
                    num[tt][ex][ey] += num[tt ^ 1][i][j];
                    num[tt][ex][ey] %= mod;
                }
            }
        tt ^= 1;
    }
    tt ^= 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int cx = 0; cx <= 10; cx ++)
                for(int cy = 0; cy <= 10; cy ++)
                    for(int h = 0; h <= hp; h ++)
                        f[0][i][j][cx][cy][h] = 0;
    f[0][X][Y][5][5][hp] = 1;
    int t = 1;
    ans = 0;
    for(int k = 1; k <= m - K; k ++) {
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++) {
                if(str[i][j] == '#') continue;
                for(int cx = 0; cx <= 10; cx ++)
                    for(int cy = 0; cy <= 10; cy ++) {
                        for(int h = 0; h <= hp; h ++) f[t][i][j][cx][cy][h] = 0;
                    }
            }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(str[i][j] == '#') continue;
                for(int cx = 0; cx <= 10; cx ++) {
                    for(int cy = 0; cy <= 10; cy ++) {
                        for(int h = hp; h > 0; h --) {
                            if(!f[t ^ 1][i][j][cx][cy][h]) continue;
                            for(int d = 0; d < 4;  d ++) {
                                int ex = i + dx[d], ey = j + dy[d];
                                if(ex < 1 || ey < 1 || ex > n || ey > n || str[ex][ey] == '#') continue;
                                int mx = ex + cx - 5 + DX, my = ey + cy - 5 + DY;
                                if(mx >= 1 && my >= 1 && mx <= n && my <= n && str[mx][my] != '#') {
                                    f[t][ex][ey][cx][cy][h] += f[t ^ 1][i][j][cx][cy][h];
                                    f[t][ex][ey][cx][cy][h] %= mod;
                                }
                                else {
                                    f[t][ex][ey][cx - dx[d]][cy - dy[d]][h - 1] += f[t ^ 1][i][j][cx][cy][h];
                                    f[t][ex][ey][cx - dx[d]][cy - dy[d]][h - 1] %= mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++) {
                if(str[i][j] == '#') continue;
                for(int cx = 0; cx <= 10; cx ++)
                    for(int cy = 0; cy <= 10; cy ++) {
                        ans = (ans + 1ll * num[tt][i][j] * f[t][i][j][cx][cy][0] % mod) % mod;
                    }
            }
        t ^= 1;
    }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}