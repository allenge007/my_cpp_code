#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5, INF = 1e6 + 5;
int n, p, q, a[maxn], b[maxn], sum[maxn], sum2[maxn];
pair<int, bitset<101>> f[maxn];
int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; i ++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    cin >> q;
    p --, q --;
    for(int i = 1; i <= n; i ++) cin >> b[i], sum2[i] = sum2[i - 1] + b[i];
    f[0].first = 0, f[0].second.reset();
    for(int i = 1; i <= p; i ++) f[i].first = -INF, f[i].second.reset();
    for(int i = 1; i <= n; i ++) {
        for(int j = min(sum[i - 1], p); j >= 0; j --) {
            if(f[j].first == -INF || j + a[i] > p) continue;
            if(f[j].first + b[i] > f[j + a[i]].first) {
                bitset<101> nxt = f[j].second;
                nxt.set(i - 1);
                f[j + a[i]] = {f[j].first + b[i], nxt};
            }
        }
    }
    for(int i = p; i >= 0; i --) {
        if(f[i].first == -INF) continue;
        if(f[i].first > q) {
            cout << "NO\n";
            for(int j = 0; j < n; j ++) {
                cout << f[i].second[j];
            }
            return 0;
        }
    }
    f[0].first = 0, f[0].second.reset();
    for(int i = 1; i <= q; i ++) f[i].first = -INF, f[i].second.reset();
    for(int i = 1; i <= n; i ++) {
        for(int j = min(sum2[i - 1], q); j >= 0; j --) {
            if(f[j].first == -INF || j + b[i] > q) continue;
            if(f[j].first + a[i] > f[j + b[i]].first) {
                bitset<101> nxt = f[j].second;
                nxt.set(i - 1);
                f[j + b[i]] = {f[j].first + a[i], nxt};
            }
        }
    }
    for(int i = q; i >= 0; i --) {
        if(f[i].first == -INF) continue;
        if(f[i].first > p) {
            cout << "NO\n";
            for(int j = 0; j < n; j ++) {
                cout << f[i].second[j];
            }
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}