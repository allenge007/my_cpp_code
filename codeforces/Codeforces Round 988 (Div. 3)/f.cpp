#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int st[maxn], h[maxn], x[maxn], n, m, k;
bool check(int mid) {
    int top = 0;
    for(int i = 1; i <= n; i ++) {

    }
}
void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int i = 1; i <= n - k + 1; i ++) {
        if(x[i + k - 1] - x[i] + 1 > 2 * m - 1) return cout << -1 << '\n', void();
    }
    int l = 1, r = 1e9;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    if(l > 1e9) return cout << -1 << '\n', void();
    cout << l << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}