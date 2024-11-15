#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n, v, m, pre[maxn], suf[maxn];
long long sa[maxn];
void solve() {
    cin >> n >> m >> v;
    for(int i = 1; i <= n; i ++) cin >> a[i], sa[i] = a[i] + sa[i - 1];
    long long sum = 0;
    for(int i = 0; i <= n + 1; i ++) pre[i] = suf[i] = 0;
    for(int i = 1; i <= n; i ++) {
        sum += a[i];
        if(sum >= v) pre[i] = 1, sum = 0;
        pre[i] += pre[i - 1];
    }
    sum = 0, suf[n + 1] = 0;
    for(int i = n; i >= 1; i --) {
        sum += a[i];
        if(sum >= v) suf[i] = 1, sum = 0;
        suf[i] += suf[i + 1];
    }
    if(pre[n] < m) return cout << -1 << endl, void();
    long long ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(pre[i] >= m) {
            ans = max(ans, sa[n] - sa[i]);
        }
        if(suf[i] >= m) ans = max(ans, sa[i - 1]);
        int l = i, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(suf[mid] >= m - pre[i]) l = mid + 1;
            else r = mid - 1;
        }
        if(r - 1 > i) ans = max(ans, sa[r - 1] - sa[i]);
    }
    cout << ans << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}