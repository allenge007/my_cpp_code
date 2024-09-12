#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
const int maxn = 1e6 + 5;
long long qpow(long long x, long long y) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        y >>= 1, basic = basic * basic % mod;
    }
    return cnt;
}
long long f[maxn], inv[maxn];
void init() {
    int n = 1000003;
    f[0] = 1ll;
    for(int i = 1; i <= n; i ++) f[i] = f[i - 1] * i % mod;
    inv[n] = qpow(f[n], mod - 2);
    for(int i = n - 1; i >= 0; i --) inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline long long C(int x, int y) {
    return f[x] * inv[y] % mod * inv[x - y] % mod;
}
void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(b < a) {
        printf("%d %lld\n", (a + b)/2, C((a + b)/2, b));
    }
    else {
        printf("%d %lld\n", b, C(b, b/2 - a/2));
    }
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}