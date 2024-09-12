#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
int n;
long long f[maxn][2], a[maxn], num[maxn][2];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    if(n == 1) return printf("%lld", a[1] % mod), 0;
    if(n == 2) return printf("%lld", 2ll * a[1] % mod), 0;
    f[2][0] = (a[1] + a[2]) % mod,  f[2][1] = (a[1] - a[2]) % mod;
    num[2][0] = 1, num[2][1] = 1;
    for(int i = 3; i <= n; i ++) {
        num[i][0] = num[i - 1][0] + num[i - 1][1];
        num[i][1] = num[i - 1][0];
        num[i][0] %= mod;
        f[i][0] = f[i - 1][0] + f[i - 1][1] + (num[i - 1][0] + num[i - 1][1]) % mod * a[i] % mod;
        f[i][1] = f[i - 1][0] - num[i - 1][0] * a[i] % mod;
        f[i][0] %= mod, f[i][1] %= mod;
    }
    printf("%lld", ((f[n][0] + f[n][1]) % mod + mod) % mod);
    return 0;
}