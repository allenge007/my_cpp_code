#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long n, b, c;
    cin >> n >> b >> c;
    if(b == 0) {
        if(c == n - 2) cout << n - 1 << '\n';
        else if(c == n - 1) cout << n - 1 << '\n';
        else if(c > n - 1) cout << n << '\n';
        else cout << -1 << '\n';
        return ;
    }
    if(c >= n) return cout << n << '\n', void();
    cout << n - max((n - c - 1) / b + 1, 0ll) << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}