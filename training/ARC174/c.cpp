#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
inline long long qpow(long long x, long long y) {
    long long cnt = 1, basic = x;
    basic %= mod, basic += mod;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
const int maxn = 1e6 + 5;
long long h1[maxn], h2[maxn], f1[maxn], f2[maxn];
int main() {
    int n;
    scanf("%d", &n);
    h2[1] = 1;
    for(int i = 2; i <= n; i ++) {
        long long p = (i - 1) * qpow(n, mod - 2) % mod, p2 = (1 - p + mod) % mod;
        h1[i] = h1[i - 1] * p % mod * p2 % mod * qpow(1 - p * p, mod - 2) % mod + h2[i - 1] * p2 % mod * qpow(1 - p * p, mod - 2) % mod;
        h2[i] = h2[i - 1] * p % mod * p2 % mod * qpow(1 - p * p, mod - 2) % mod + h1[i - 1] * p2 % mod * qpow(1 - p * p, mod - 2) % mod;
        f1[i] = f1[i - 1] + h1[i - 1] * p % mod * qpow(1 - p * p, mod - 2) % mod + h2[i - 1] * (qpow(1 - p * p, mod - 2) - 1) % mod;
        f2[i] = f2[i - 1] + h2[i - 1] * p % mod * qpow(1 - p * p, mod - 2) % mod + h1[i - 1] * (qpow(1 - p * p, mod - 2) - 1) % mod;
        f1[i] %= mod, f2[i] %= mod, h1[i] %= mod, h2[i] %= mod;
    }
    printf("%lld %lld\n", f1[n], f2[n]);
    return 0;
}