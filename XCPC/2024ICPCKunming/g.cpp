#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    i64 a, b;
    cin >> a >> b;
    int ans = 20;
    auto dfs = [&ans](auto&& self, i64 a, i64 b, int k) -> void {
        if(k > 20) return ;
        if(a == 0 || b == 0) return ans = min(ans, k + 1), void();
        self(self, a - __gcd(a, b), b, k + 1);
        self(self, a, b - __gcd(a, b), k + 1);
    };
    dfs(dfs, a, b, 0);
    cout << ans << endl;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}