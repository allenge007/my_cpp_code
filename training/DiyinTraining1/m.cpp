#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    int p = 0;
    for(int i = 1; i < n; i ++) {
        cout << "? " << p << " " << p << " " << i << " " << i << endl;
        cout.flush();
        string x;
        cin >> x;
        if(x[0] == '<') p = i;
    }
    int p2 = 0;
    if(p == 0) p2 = 1;
    vector<int> pos;
    pos.push_back(p2);
    for(int i = 0; i < n; i ++) {
        if(i == p || i == p2) continue;
        cout << "? " << p << " " << p2 << " " << p << " " << i << endl;
        string x;
        cin >> x;
        if(x[0] == '<') p2 = i, pos.clear(), pos.push_back(p2);
        else if(x[0] == '=') pos.push_back(i);
    }
    int siz = pos.size();
    int ans = pos[0];
    for(auto i = 1; i < siz; i ++) {
        cout << "? " << ans << " " << ans << " " << pos[i] << " " << pos[i] << endl;
        cout.flush();
        string x;
        cin >> x;
        if(x[0] == '>') ans = pos[i];
    }
    cout << "! " << p << " " << ans << endl;
    cout.flush();
}
int main() {
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}