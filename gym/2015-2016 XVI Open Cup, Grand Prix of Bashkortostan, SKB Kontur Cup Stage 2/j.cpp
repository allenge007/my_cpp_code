#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5, INF = 1e6 + 5;
int n, p, q, a[maxn], b[maxn], sum[maxn];
pair<int, bitset<101>> f[maxn];
int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; i ++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    cin >> q;
    for(int i = 1; i <= n; i ++) cin >> b[i];
    f[0].first = 0, f[0].second.reset();
    for(int i = 1; i <= p; i ++) f[i].first = INF, f[i].second.reset();
    for(int i = 1; i <= n; i ++) {
        for(int j = p; j >= 0; j --) {
            if(f[j].first + b[i] < f[min(p, j + a[i])].first) {
                auto nxt = f[j].second;
                nxt.set(n - i);
                f[min(j + a[i], p)] = {f[j].first + b[i], nxt};
            }
        }
    }
    if(f[p].first >= q) cout << "YES\n";
    else cout << "NO\n" << f[p].second.to_string().substr(101 - n, n) << endl;
    return 0;
}