#include <bits/stdc++.h>

using namespace std;
string str;
bool check(int p) {
    return str[p - 3] == '1' && str[p - 2] == '1' && str[p - 1] == '0' && str[p] == '0';
}
void solve() {
    cin >> str;
    int q;
    cin >> q;
    int n = str.size();
    int cnt = 0;
    for(int i = 3; i < n; i ++) {
        if(check(i)) cnt ++;
    }
    while(q --) {
        int p, v;
        cin >> p >> v;
        p --;
        for(int i = 0; i < 4; i ++) if(check(p + i)) cnt --;
        str[p] = v + '0';
        for(int i = 0; i < 4; i ++) if(check(p + i)) cnt ++;
        if(cnt) cout << "YES\n";
        else cout << "NO\n";
    }
}
int main() {
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}