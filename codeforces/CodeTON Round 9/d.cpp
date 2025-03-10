#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int S[maxn], a[maxn];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) cin >> S[i];
    sort(S + 1, S + m + 1, greater<int>());
    a[1] = 1;
    for(int i = 2; i <= n; i ++) {
        int ans = 0;
        a[i] = 0;
        for(int j = 1; j * j <= i; j ++) {
            if(i % j == 0) {
                ans = max(ans, max(a[j], a[i / j]));
            }
        }
        a[i] = ans + 1;
    }
    for(int i = 1; i <= n; i ++) if(a[i] > m) return cout << -1 << '\n', void();
    for(int i = 1; i <= n; i ++) cout << S[a[i]] << " ";
    cout << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}