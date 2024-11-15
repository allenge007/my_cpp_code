#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int p[maxn];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i < n; i ++) {
        if(p[i] != i) {
            if(abs(p[i + 1] - p[i]) != 1) return cout << "NO" << endl, void();
            swap(p[i], p[i + 1]);
            if(p[i] != i) return cout << "NO" << endl, void();
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}