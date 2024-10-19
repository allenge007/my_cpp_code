#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
int a[maxn], n, cnt[maxn];
long long fac[maxn], ifac[maxn], g[maxn], tmp[maxn], mini[maxn], suf[maxn];
long long C(int x, int y) {
    return fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}
long long qpow(int x, int y) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) cnt[i] = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), cnt[a[i]] ++;
    for(int i = 0; i < n; i ++) g[i] = 1;
    int mini = n + 1;
    long long tot = 0;
    suf[n] = 0;
    for(int i = n - 1; i >= 0; i --) suf[i] = cnt[i] + suf[i + 1];
    for(int i = 0; i < n; i ++) {
        long long tmp = 0;
        mini = min(mini, cnt[i]);
        for(int j = 0; j <= cnt[i]; j ++) {
            long long ans = qpow(2, cnt[i]) - tmp;
            ans %= mod;
            tmp += C(cnt[i], j);
            g[j] = g[j] * ans % mod;
        }
        for(int j = 0; j <= mini; j ++) {
            if(j != mini) tot += j * (g[j] - g[j + 1]) % mod * qpow(2, suf[i + 1]) % mod;
            else tot += j * g[j] % mod * qpow(2, suf[i + 1]) % mod;
            tot %= mod;
        }
    }
    printf("%lld\n", (tot + mod) % mod);
}
int main() {
    int T;
    fac[0] = 1;
    for(int i = 1; i <= 200000; i ++) fac[i] = fac[i - 1] * i % mod;
    ifac[200000] = qpow(fac[200000], mod - 2);
    for(int i = 199999; i >= 0; i --) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    // cout << C(6, 4) << endl;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}