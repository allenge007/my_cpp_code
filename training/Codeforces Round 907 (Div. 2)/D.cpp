#include <bits/stdc++.h>

using namespace std;
#define int long long
const long long mod = 1e9 + 7;
long long solve(long long x) {
    if(x == 3) return 0ll;
    long long ans = 0ll;
    for(unsigned long long i = 2; (1ll << i) <= x; i ++) {
        unsigned long long l = (1ll << i), r = min((1ll << (i + 1ll)) - 1ll, x);
        long long basic = i, cnt = 1ll;
        while(basic * i <= l) {
            basic *= i, cnt ++;
        }
        ans += cnt * ((r - l + 1ll) % mod) % mod;
        ans %= mod;
        while(basic * i <= r) {
            ans += (r - max(l, basic * i) + 1) % mod;
            ans %= mod;
            basic *= i, cnt ++;
        }
        ans %= mod;
    }
    return ans;
}
signed main() {
    int q;
    scanf("%lld", &q);
    while(q --) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        // printf("%lld\n", solve(r));
        printf("%lld\n", (solve(r) - solve(l - 1) + mod) % mod);
    }
    return 0;
}