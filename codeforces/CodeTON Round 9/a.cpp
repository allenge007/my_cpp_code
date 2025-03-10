#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cout << 2 * i - 1 << " ";
    }
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