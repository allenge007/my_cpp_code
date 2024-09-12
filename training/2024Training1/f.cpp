#include <bits/stdc++.h>

using namespace std;
const int maxn = 255;
const long long mod = 998244353;
long long f[maxn][maxn][maxn], sum[maxn][maxn][maxn];
int n, a[maxn];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            for(int k = 1; k <= n; k ++) {
                if(a[i] == a[j] && a[j] == a[k]) {
                    f[i][j][k] = sum[i - 1][j - 1][k - 1] + 1;
                    f[i][j][k] %= mod;
                }
                sum[i][j][k] = f[i][j][k] + sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i - 1][j - 1][k] - sum[i - 1][j][k - 1] - sum[i][j - 1][k - 1] + sum[i - 1][j - 1][k - 1];
                sum[i][j][k] %= mod;
            }
        }
    }
    printf("%lld\n", (sum[n][n][n] + mod) % mod);
    return 0;
}