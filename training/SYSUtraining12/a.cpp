#include <bits/stdc++.h>

using namespace std;
const long long mod  = 1e9 + 7;
const int maxn = 1005;
long long f[maxn][maxn][3];
void solve() {
    int n, K;
    scanf("%d%d", &n, &K);
    printf("%lld\n", (f[n][K][0] + f[n][K][1]) % mod);
}
int main() {
    int n = 1000;
    f[1][0][0] = 1;
    for(int i = 2; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            f[i][j][0] = max((i - j - 2ll), 0ll) * f[i - 1][j][0] + (i - j - 1) * f[i - 1][j][1];
            f[i][j][0] += f[i - 1][j + 1][0] * (j + 1);
            f[i][j][0] += f[i - 1][j + 1][1] * j;
            f[i][j][0] %= mod;
            f[i][j][1] = f[i - 1][j - 1][1] + f[i - 1][j][1] + f[i - 1][j - 1][0] * 2;
            f[i][j][1] %= mod;
        }
    }
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}

/*
f(0, 0, 0) = 1
f(1, 0, 0) = 1
f(2, 1, 1) = 2
f(3, 1, 0) = 2, f(3, 1, 1) = 2, f(3, 2, 1) = 2
f(4, 0, 0) = 2, f(4, 1, 0) = 8, f(4, 1, 1) = 2, f(4, 2, 0) = 2, f(4, 2, 1) = 8, f(4, 3, 1) = 2
*/