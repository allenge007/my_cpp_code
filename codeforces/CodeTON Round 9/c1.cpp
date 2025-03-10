#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e6 + 5;
void solve() {
    int x;
    long long m, ans = 0;
    cin >> x >> m;
    for(int i = 1; i <= min(2ll * x, m); i ++) {
        int res = x ^ i;
        if(!res) continue;
        if(x % res == 0 || i % res == 0) {
            ans ++;
        }
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