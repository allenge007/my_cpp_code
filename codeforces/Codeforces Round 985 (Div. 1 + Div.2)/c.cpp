#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 5;
int a[maxn], f[maxn][2], n;
int sign(int x) {
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int maxi = 0;
    f[0][1] = -1;
    for(int i = 1; i <= n; i ++) {
        f[i][0] = sign(a[i] - f[i - 1][0]) + f[i - 1][0];
        f[i][1] = max(maxi, f[i - 1][1] + sign(a[i] - f[i - 1][1]));
        maxi = max(maxi, f[i][0]);
    }
    cout << f[n][1] << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}