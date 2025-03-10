#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
string str;
void solve() {
    cin >> str;
    int n = str.size();
    for(int i = 0; i < n; i += 2) {
        if(str[i] != '2') str[i] ^= 1;
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i ++) {
        if(str[i] == '0') cnt0 ++;
        else if(str[i] == '1') cnt1 ++;
        else cnt2 ++;
    }
    if(abs(cnt0 - cnt1) >= cnt2) cout << abs(cnt0 - cnt1) - cnt2 << '\n';
    else cout << ((cnt2 - abs(cnt0 - cnt1))&1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}