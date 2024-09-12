#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
int n, k;
long long fac[maxn], g[maxn];
long long qpow(long long x, long long y) {
    long long cnt = 1, basic = x;;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &k);
    fac[0] = 1;
    for(int i = 1; i <= n + 1; i ++) fac[i] = fac[i - 1] * i % mod;
    long long ans = 0;
    for(int i = max(n - k, 0); i <= n; i ++) {
        g[i] = fac[n - i] * qpow(n - i + 1, max(k - n + i + 1, 0)) % mod;
    }
    for(int i = max(n - k, 0); i <= n; i ++) {
        ans += (g[i] - g[i + 1]) * fac[n] % mod * qpow(fac[i], mod - 2) % mod;
        ans %= mod;
    }
    printf("%lld", (ans + mod) % mod);
    return 0;
}