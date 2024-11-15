#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, a, b;
    string s;
    cin >> n >> a >> b;
    int x = 0, y = 0;
    cin >> s;
    string pre;
    for(int i = 1; i <= 100; i ++) pre += s;
    n = pre.size();
    for(int i = 0; i < n; i ++) {
        if(x == a && y == b) return cout << "YES\n", void();
        if(pre[i] == 'N') y ++;
        else if(pre[i] == 'E') x ++;
        else if(pre[i] == 'S') y --;
        else x --;
    }
    if(x == a && y == b) return cout << "YES\n", void();
    cout << "NO\n";
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}