#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 27, maxm = 1e7 + 5;
const long long mod = 998244353;
long long qpow(long long x, long long y = mod - 2) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
int h[maxn];
long long fac[maxm];
void solve() {
    int n = read();
    int cnt = 0;
    long long sum = 0;
    for(int i = 1; i <= n; i ++) {
        h[i] = read();
        if(h[i] & 1) cnt ++, sum += h[i] - 1;
        else sum += h[i];
    }
    if(cnt > 1) return printf("%lld\n", qpow(2)), void();
    long long p = 1ll;
    for(int i = 1; i <= n; i ++) {
        if(h[i] & 1) p *= fac[h[i]];
        else p *= fac[h[i] - 1];
        p %= mod;
    }
    if(sum) p *= qpow(fac[sum - 1]), p %= mod;
    if(cnt) p *= qpow(sum + 1), p %= mod;
    printf("%lld\n", cnt ? (1 + p) * qpow(2) % mod : ((1 - p) * qpow(2) % mod + mod) % mod);
}
int main() {
    fac[1] = 1ll;
    for(int i = 3; i <= 10000000; i += 2) fac[i] = fac[i - 2] * i % mod;
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}