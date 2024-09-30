#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
int T, a[maxn], n;
long long f[10][10][2][2][2], p[maxn];
inline long long qpow(long long x, long long y = mod - 2) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%lld", &p[i]);
    long long ans = 0, inv = qpow(10000);
    for(int i = 1; i <= n; i ++) p[i] = p[i] * inv % mod;
    int t = 0;
    for(int i = 0; i <= 9; i ++) {
        for(int j = 0; j <= 9; j ++) {
            f[i][j][0][0][0] = 1, f[i][j][0][0][1] = f[i][j][0][1][0] = f[i][j][0][1][1] = 0;
            t = 0;
            for(int k = 1; k <= n; k ++) {
                int t1 = (a[k] >> i) & 1, t2 = (a[k] >> j) & 1;
                f[i][j][t ^ 1][0][0] = f[i][j][t][t1][t2] * p[k] % mod + f[i][j][t][0][0] * (1ll - p[k]) % mod;
                f[i][j][t ^ 1][0][1] = f[i][j][t][t1][t2 ^ 1] * p[k] % mod + f[i][j][t][0][1] * (1ll - p[k]) % mod;
                f[i][j][t ^ 1][1][0] = f[i][j][t][t1 ^ 1][t2] * p[k] % mod + f[i][j][t][1][0] * (1ll - p[k]) % mod;
                f[i][j][t ^ 1][1][1] = f[i][j][t][t1 ^ 1][t2 ^ 1] * p[k] % mod + f[i][j][t][1][1] * (1ll - p[k]) % mod;
                for(auto l : {0, 1}) for(auto r : {0, 1}) f[i][j][t][l][r] %= mod;
                t ^= 1;
            }
        }
    }
    for(int i = 0; i <= 9; i ++) {
        for(int j = 0; j <= 9; j ++) {
            ans += f[i][j][t][1][1] * (1ll << i + j) % mod;
            ans %= mod;
        }
    }
    printf("%lld\n", (ans + mod) % mod);
}
int main() {
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}