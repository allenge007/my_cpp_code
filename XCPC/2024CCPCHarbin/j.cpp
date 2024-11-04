#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
const int maxn = 1e5 + 5, INF = 1e9 + 7;
int n, m, p[maxn], t[maxn], a[maxn], tail[maxn], na[maxn];
vector<int> bat[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i], bat[i].clear(), tail[i] = 0;
    for(int i = 1; i <= m; i ++) {
        cin >> p[i] >> t[i];
        bat[t[i]].push_back(p[i]);
    }
    for(int i = 1; i <= n; i ++) bat[i].push_back(INF), na[i] = a[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for(int i = 1; i <= n; i ++) Q.push({bat[i][0], i});
    long long now = 0;
    for(int i = 1; i <= m; i ++) {
        while(!Q.empty() && Q.top().fir <= p[i]) {
            auto u = Q.top();
            Q.pop();
            if(now + na[u.sec] <= p[i]) now += na[u.sec], na[u.sec] = 0;
            else na[u.sec] -= p[i] - now, now = p[i];
        }
        while(!Q.empty() && now < p[i]) {
            auto u = Q.top();
            if(now + na[u.sec] <= p[i]) now += na[u.sec], na[u.sec] = 0, Q.pop();
            else {
                na[u.sec] -= p[i] - now, now = p[i];
                break;
            }
        }
        if(now < p[i]) break;
        na[t[i]] = a[t[i]];
        Q.push({bat[t[i]][++ tail[t[i]]], t[i]});
    }
    for(int i = 1; i <= n; i ++) now += na[i];
    cout << now << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}