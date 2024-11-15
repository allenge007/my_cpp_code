#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s, r;
    int n, cnt0 = 0, cnt1 = 0;
    cin >> n >> s >> r;
    for(int i = 0; i < n; i ++) 
        if(s[i] == '0') cnt0 ++;
        else cnt1 ++;
    if(cnt0 == 0 || cnt1 == 0) return cout << "No" <<endl, void();
    for(int i = 0; i < n - 2; i ++) {
        if(r[i] == '0') cnt1 --;
        else cnt0 --;
        if(cnt0 == 0 || cnt1 == 0) return cout << "No" <<endl, void();
    }
    cout << "Yes" << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}