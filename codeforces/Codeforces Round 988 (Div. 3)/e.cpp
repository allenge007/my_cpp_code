#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 5;
void solve() {
    int n, flag = 0, p = 0, las = 0;
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        cout << "? " <<  1 << " " << i << endl;
        cout.flush();
        int x;
        cin >> x;
        if(x) {
            if(x == i - 1) {
                p = 1, las = i;
            } else {
                p = i - x, las = i;
            }
            break;
        }
    }
    if(!p) return cout << "! IMPOSSIBLE" << endl, cout.flush(), void();
    string ans;
    for(int i = 1; i < p; i ++) ans += '1';
    for(int i = p; i < las; i ++) ans += '0';
    ans += '1';
    long long lasx = 1;
    for(int i = las + 1; i <= n; i ++) {
        cout << "? " << las - 1 << " " << i << endl;
        cout.flush();
        long long x;
        cin >> x;
        if(x > lasx) ans += '1';
        else ans += '0';
        lasx = x;
    }
    cout << "! " << ans << endl;
    cout.flush();
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}