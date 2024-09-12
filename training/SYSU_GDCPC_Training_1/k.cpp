#include <bits/stdc++.h>

using namespace std;
#define LL long long
const LL mod = 998244353;
const int maxn = 1e6 + 5;
LL qpow(LL x, LL k) {
    LL cnt = 1, basic = x;
    while(k) {
        if(k & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, k >>= 1;
    }
    return cnt;
}
LL a[maxn];
int n, x[maxn];
double A[maxn];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &x[i]);
    a[0] = 1, A[0] = 1;
    for(int i = 1; i <= n; i ++){
        a[i] = a[i - 1] * (2ll * i - 1) % mod * qpow(2 * i, mod - 2) % mod;
        // A[i] = A[i - 1] * (2.0 * i - 1.0)/(2.0 * i);
    }
        
    LL ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += a[i - 1] * a[n - i] %mod * x[i] % mod;
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}