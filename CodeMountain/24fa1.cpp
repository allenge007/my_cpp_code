#include <bits/stdc++.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)) {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int maxn = 205, maxk = 20;
const long long INF = 1e18 + 7;
int n, m, K;
long long f[1 << maxk][30], dis[maxn][maxn][maxn];
int q[maxn][4], uni[maxn], cnt, full, id[maxn];
bool vis[1 << maxk][30];
inline long long dfs(int s, int x) {
    if(s == full) {
        return f[s][x] = 0;
    }
    if(vis[s][x]) return f[s][x];
    vis[s][x] = 1, f[s][x] = INF;
    int tmp = s;
    for(register int i = 0; i < K; ++ i) {
        auto t2 = tmp;
        int num2 = ((tmp >> (i << 1))&1) + (((tmp >> (i << 1 | 1)) & 1) << 1) + 1;
        if(num2 > q[i][0]) continue;
        int y = q[i][num2];
        if(y == uni[x]) continue;
        for(register int j = 0; j < K; ++ j) {
            int num = ((tmp >> (j << 1))&1) + (((tmp >> (j << 1 | 1)) & 1) << 1) + 1;
            if(num > q[j][0]) continue;
            if(q[j][num] == y) {
                if(((num >> 1) & 1) ^ ((t2 >> (j << 1 | 1)) & 1)) t2 ^= (1 << (j << 1 | 1));
                if((num & 1) ^ ((t2 >> (j << 1)) & 1)) t2 ^= (1 << (j << 1));
            }
        }
        if(tmp ^ t2) {
            long long res = dfs(t2, id[y]);
            if(res ^ INF) f[s][x] = min(f[s][x], res + dis[n][uni[x]][y]);
        }
    }
    return f[s][x];
}
int main() {
    n = read(), m = read(), K = read();
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            if(i != j) dis[0][i][j] = INF;
    for(int i = 1; i <= m; ++ i) {
        int x, y, z;
        x = read(), y = read(), z = read();
        dis[0][x][y] = z;
        dis[0][y][x] = z;
    }
    for(int i = 0; i < K; ++ i) {
        int s;
        s = read();
        q[i][0] = s;
        for(int j = 1; j <= s; ++ j) {
            q[i][j] = read();
            uni[++ cnt] = q[i][j];
        }
        if(s & 2) full |= 1 << (i << 1 | 1);
        if(s & 1) full |= 1 << (i << 1);
    }
    uni[++ cnt] = 1;
    sort(uni + 1, uni + cnt + 1);
    cnt = unique(uni + 1, uni + cnt + 1) - uni - 1;
    for(int i = 1; i <= cnt; i ++) id[uni[i]] = i;
    for(int k = 1; k <= n; ++ k) {
        for(int i = 1; i <= n; ++ i) {
            for(int j = 1; j <= n; ++ j) {
                dis[k][i][j] = min(dis[k - 1][i][j], dis[k - 1][i][k] + dis[k - 1][k][j]);
            }
        }
    }
    int p = 0;
    for(int i = 0; i < K; ++ i) {
        if(q[i][1] == 1) p |= 1 << (i << 1); 
    }
    printf("%lld\n", dfs(p, 1));
    return 0;
}