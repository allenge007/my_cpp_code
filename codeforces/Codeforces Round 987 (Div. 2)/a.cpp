#include <bits/stdc++.h>

using namespace std;
const int maxn = 55;
int h[maxn], f[maxn];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    f[0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        f[i] = 0;
        for(int j = 0; j < i; j ++) if(h[i] >= h[j]) f[i] = max(f[i], f[j]);
        f[i] ++;
        ans = max(ans, f[i]);
    }
    cout << n - ans << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}