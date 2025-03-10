#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int mod = 1e9 + 7, maxn = 1e5 + 5;
i64 fac[maxn], ifac[maxn];
i64 qpow(i64 x, i64 y) {
    i64 res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
i64 C(i64 n, i64 m) {
    if(n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
i64 A(i64 n, i64 m) {
    if(n < m) return 0;
    return fac[n] * ifac[n - m] % mod;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    fac[0] = 1;
    for(int i = 1; i <= n; i ++) fac[i] = fac[i - 1] * i % mod;
    ifac[n] = qpow(fac[n], mod - 2);
    for(int i = n - 1; i >= 0; i --) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    i64 ans = 0;
    for(int i = 0; i <= k; i ++) {
        int z = 1;
        if(i&1) z = -1;
        ans += z * C(k, i) * A(n - i, k - i) % mod;
    }
    cout << (ans % mod+ mod) % mod << endl;
    return 0;
}