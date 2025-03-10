#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if(n < 2) return cout << -1 << '\n', void();
    for(int i = 1; i < n; i ++) {
        if(s[i] == s[i - 1]) {
            return cout << s[i - 1] << s[i] << '\n', void();
        }
    }
    for(int i = 2; i < n; i ++) {
        if(s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
            return cout << s[i - 2] << s[i - 1] << s[i] << '\n', void();
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}