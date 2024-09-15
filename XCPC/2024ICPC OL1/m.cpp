#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;

    vector<int> num(26);
    vector<map<string, int>> vst(26);
    string team, prob, stat;
    for(int i = 1; i <= n; ++i) {
        cin >> team >> prob >> stat;
        if(stat == "accepted") {
            num[prob[0] - 'A'] += 1 - vst[prob[0] - 'A'][team];
            vst[prob[0] - 'A'][team] = 1;
        }
    }

    int mx = 0;
    for(int i = 0; i < 26; ++i)
        if(num[i] > num[mx]) mx = i;
    cout << mx + 'A' << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) solve();
    return 0;
}