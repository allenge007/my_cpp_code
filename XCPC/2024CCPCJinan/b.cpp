#include <bits/stdc++.h>

using namespace std;
int card[4], t[6], tc[4];
int check(int x) {
    int cnt = 0, lft = 0;
    for(int i = 0; i < 4; i ++) {
        tc[i] = card[i];
        if((x >> i) & 1) ;
        else lft += card[i];
    }
    int cha = t[4] + t[5];
    for(int i = 0; i < 4; i ++) {
        if((x >> i) & 1) {
            int dis = 5 - tc[i];
            if(dis <= min(lft, t[i] * 3 + cha)) {
                lft -= min(dis, min(lft, t[i] * 3 + cha));
                if(t[i] * 3 < dis) cha -= dis - t[i] * 3;
                cnt ++;
            }
        }
    }
    return cnt;
}
void solve() {
    int n;
    cin >> n;
    card[0] = card[1] = card[2] = card[3] = 0;
    for(int i = 1; i <= n; i ++) {
        string x;
        cin >> x;
        if(x[1] == 'D') card[0] ++;
        if(x[1] == 'C') card[1] ++;
        if(x[1] == 'H') card[2] ++;
        if(x[1] == 'S') card[3] ++;
    }
    for(int i = 0; i < 6; i ++) cin >> t[i];
    int ans = 0, cnt = 0;
    for(int i = 0; i < 4; i ++) ans += card[i] / 5, card[i] %= 5;
    for(int i = 0; i < (1 << 4); i ++) {
        cnt = max(cnt, check(i));
    }
    cout << ans + cnt << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}