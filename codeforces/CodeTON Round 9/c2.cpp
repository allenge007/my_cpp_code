#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
long long a[maxn << 2];
void solve() {
    int x;
    long long m, ans = 0;
    cin >> x >> m;
    int tmp = x, k = 0, n = 0;
    while(tmp) tmp >>= 1, k ++;
    n = 1 << k;
    for(int i = 0; i < n; i ++) a[i] = 0;
    a[0] = (m - x) / n;
    for(int i = 2; i <= n; i ++) {
        int lft = ((long long) i * x % n) ^ x;
        a[lft] += max((m - (long long) lft) / n + 1, 0ll);
    }
    for(int i = 0; i < n; i ++) {
        if(i > m) break;
        int res = x ^ i;
        if(i == 0) {
            ans += a[i];
            continue;
        }
        if(res % x != 0 || res % i == 0) ans ++;
        ans += a[i];
    }
    cout << ans << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}