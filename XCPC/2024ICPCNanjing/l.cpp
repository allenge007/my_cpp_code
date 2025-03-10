#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;

    if(n != (n & -n)) {
        cout << "No" << '\n';
        return;
    }

    vector<int> p(n);
    for(int i = 0; i < n; i += 2) p[i] = n - 1 - i / 2, p[i + 1] = i / 2;

    for(int i = 0; i < n; ++i) cout << i << " \n"[i == n - 1];
    for(int i = 0; i < n; ++i) cout << p[i] << " \n"[i == n - 1];

    for(int i = 0; i < n; ++i) cout << (i ^ p[i]) << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}