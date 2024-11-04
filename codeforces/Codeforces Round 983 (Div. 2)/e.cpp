#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int n;
long long sum[maxn << 2], a[maxn << 2], p[maxn << 2];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i], a[i + 2 * n] = a[i + n] = a[i];
    for(int i = 0; i < 3 * n; i ++) {
        if(i) sum[i] = sum[i - 1];
        sum[i] += (i & 1) ? a[i] : -a[i];
    }
    p[0] = 0;
    for(int i = 0; i < 2 * n; i += 2) {
        p[i + 2] = p[(i + 2) % n] = p[i] + sum[i + n] - sum[i + 1];
    }
    for(int i = 0; i < n; i ++) {
        a[i] = p[(i - 1 + n) % n] + p[(i + 1) % n] + 2 * p[i] + a[i];
    }
    long long ans = a[0], mini = 0;
    for(int i = 1; i < n; i ++) if(a[i] != ans) return printf("-1\n"), void();
    for(int i = 0; i < n; i ++) mini = min(mini, p[i]);
    for(int i = 0; i < n; i ++) cout << p[i] - mini << " ";
    cout << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}