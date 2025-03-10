#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    i64 n, k;
    cin >> n >> k;
    auto ask1 = [](auto&& self, i64 n, i64 k) -> i64 {
        if(k == 1 || n <= k) return n;
        i64 tmp = self(self, n - (n + k - 1) / k, k);
        return tmp + (tmp + k - 2) / (k - 1);
    };
    if(k * k <= n) cout << ask1(ask1, n, k) << endl;
    else {
        i64 ans = 1;
        for(int i = 1; i <= n / k + 1; i ++) {
            i64 lim = 1ll * i * k;
            if(lim < n) ans += 1ll * (lim - ans) / i * i;
            else {
                ans += 1ll * (n - ans) / i * i;
                break;
            }
        }
        cout << ans << endl;
    }
}
int main() {
    ios :: sync_with_stdio(false);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}