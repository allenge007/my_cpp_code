#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const long long mod = 998244353;
int n, m, a[maxn], b[maxn], sum[maxn];
long long f[10005];
inline long long qpow(int x, int y = mod-2) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]);
    f[0] = 1;
    for (int i = 1; i <= n; i ++){
        for(int j = sum[i]; j >= a[i]; j --) {
            f[j] -= f[j - a[i]], f[j] %= mod;
        }
    }
    long long ans = n + m;
    for (int i = 1; i <= m; i ++) {
        for (int j = 0; j <= sum[n]; j ++)
            ans -= 1ll * b[i] * qpow(j + b[i]) % mod * f[j] % mod, ans %= mod;
    }
    printf("%lld", (ans % mod + mod) % mod);
    return 0;
}
