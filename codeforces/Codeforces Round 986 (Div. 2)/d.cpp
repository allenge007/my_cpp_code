#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int p[maxn][3], n;
bool ok(int x, int y) {
    return !(p[x][0] < p[y][0] && p[x][1] < p[y][1] && p[x][2] < p[y][2]);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i][0];
    for(int i = 1; i <= n; i ++) cin >> p[i][1];
    for(int i = 1; i <= n; i ++) cin >> p[i][2];
    for(int i = 2; i < n; i ++) {
        if(ok(1, i) && ok(i, n)) {
            cout << "YES\n";
            cout << 2 << endl;
            if(p[1][0] > p[i][0]) cout << "q " << i << endl;
            else if(p[1][1] > p[i][1]) cout << "k " << i << endl;
            else cout << "j " << i << endl;
            if(p[i][0] > p[n][0]) cout << "q " << n << endl;
            else if(p[i][1] > p[n][1]) cout << "k " << n << endl;
            else cout << "j " << n << endl;
            return ;
        }
    }
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