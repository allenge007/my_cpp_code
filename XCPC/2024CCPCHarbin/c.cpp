#include <bits/stdc++.h>

using namespace std;
char turn(char from, char to) {
    if(from == to) return 'Z';
    if(from == 'N') {
        if(to == 'E') return 'R';
        if(to == 'W') return 'L';
    }
    if(from == 'E') {
        if(to == 'N') return 'L';
        if(to == 'S') return 'R';
    }
    if(from == 'S') {
        if(to == 'E') return 'L';
        if(to == 'W') return 'R';
    }
    if(from == 'W') {
        if(to == 'N') return 'R';
        if(to == 'S') return 'L';
    }
    return 'E';
}
void solve() {
    int n;
    cin >> n;
    vector<pair<char, int>> ans;
    char las;
    for(int i = 1; i <= n; i ++) {
        char dir;
        int x;
        cin >> dir >> x;
        if(i == 1) ans.push_back({dir, 0}), ans.push_back({'Z', x});
        else {
            ans.push_back({turn(las, dir), 0});
            ans.push_back({'Z', x});
        }
        las = dir;
    }
    cout << ans.size() - 1 << " " << ans[0].first << endl;
    int cnt = ans.size();
    for(int i = 1; i < cnt; i ++) {
        cout << ans[i].first;
        if(ans[i].second) cout << " " << ans[i].second;
        cout << endl;
    }
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}