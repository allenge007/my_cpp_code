#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 9;
const int maxn = 1e6 + 5;
inline long long qpow(long long x, long long y = mod - 2) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
int n, m;
long long fac[maxn];
int main() {
    scanf("%d%d", &n, &m);
    fac[0] = 1;
    for(int i = 1; i <= max(n, m); i ++) fac[i] = fac[i - 1] * i % mod;
    long long r = 1ll * n * (n - 1) / 2, ans = 1;
    for(long long y = r; y >= r - m + 1; y --) ans = y % mod * ans % mod;
    ans = ans * qpow(fac[m]) % mod * fac[n] % mod;
    printf("%lld\n", ans);
    return 0;
}