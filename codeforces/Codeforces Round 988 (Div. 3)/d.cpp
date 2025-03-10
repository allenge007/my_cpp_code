#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int l[maxn], r[maxn], x[maxn], v[maxn];
void solve() {
    int n, m, L, lim = 0;
    cin >> n >> m >> L;
    for(int i = 1; i <= n; i ++) {
        cin >> l[i] >> r[i];
        if(L >= l[i] && L <= r[i]) {
            return cout << -1 << "\n", void();
        }
        if(r[i] < L) lim = max(lim, r[i] - l[i] + 1);
    }
    vector<pair<int, int>> q;
    int tot = 1, bnd = 0;
    for(int i = 1; i <= m; i ++) {
        cin >> x[i] >> v[i];
        while(tot <= n && x[i] > r[tot]) {
            bnd = max(bnd, r[tot] - l[tot] + 1), tot ++;
        }
        q.push_back({bnd, i});
    }
    priority_queue<int> pq;
    int maxi = 1, tail = -1;
    for(int i = 0; i < m; i ++) {
        if(q[i].first >= 1) break;
        pq.push(v[q[i].second]);
        tail = i + 1;
    }
    if(tail == -1) return cout << -1 << '\n', void();
    int ans = 0;
    while(!pq.empty()) {
        if(maxi > lim) break;
        maxi += pq.top(), ans ++;
        pq.pop();
        while(tail < m && maxi > q[tail].first) pq.push(v[q[tail ++].second]);
    }
    if(maxi <= lim) return cout << "-1" << '\n', void();
    cout << ans << '\n';
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}