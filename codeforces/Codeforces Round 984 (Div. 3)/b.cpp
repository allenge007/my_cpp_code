#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int n, k, sum[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= k; i ++) {
        int b, c;
        cin >> b >> c;
        sum[b] += c;
    }
    sort(sum + 1, sum + k + 1, greater<int>());
    int lim = min(n, k), ans = 0;
    for(int i = 1; i <= lim; i ++) ans += sum[i];
    cout << ans << '\n';
    for(int i = 1; i <= k; i ++) sum[i] = 0;
}
int main() {
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}