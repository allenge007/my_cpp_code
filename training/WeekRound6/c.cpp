#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long maxn = 2e5 + 10;

long long ans, b[maxn], cnt, f[maxn];
int n, a[maxn];
int main() {
    ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] < i || a[a[i]] != a[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (!b[a[i]]) b[a[i]] = i;
        else {
            int tmp = a[i];
            a[i] = b[a[i]];
            b[tmp] = i;
            f[a[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) cnt++;
        if (a[i] == i) {
            ans = ans * cnt % mod;
            cnt--;
        }
    }
    cout << ans << endl;
    return 0;
}