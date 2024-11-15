#include <bits/stdc++.h>

using namespace std;
void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    cout << max(0, r/k - l + 1) << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}