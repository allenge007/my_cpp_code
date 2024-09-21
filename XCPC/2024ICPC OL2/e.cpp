#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Robot {
    int pos, step;
    bool operator < (const Robot &o) const {
        return step < o.step;
    }
};

void print(vector<int> &f, const int &k, const int &n) {
    if(f[k]) print(f, f[k], n), cout << " ";
    cout << (k > n ? k - n : k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<vector<int>> G(n+n+1);
        for(int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v+n), G[v+n].push_back(u);
            G[v].push_back(u+n), G[u+n].push_back(v);
        }

        int k;
        cin >> k;
        queue<Robot> q;
        for(int i = 1; i <= k; ++i) {
            int s;
            cin >> s;
            q.push({ s, d });
        }

        vector<int> bad(n+n+1, INF);
        while(q.size()) {
            int u = q.front().pos, s = q.front().step; q.pop();
            if(s == 0) continue;
            for(int v : G[u]) {
                if(bad[v] == INF) q.push({ v, s-1 }), bad[v] = d - s;
            }
        }

        queue<int> qq;
        vector<int> dst(n+n+1, INF), from(n+n+1, 0);
        dst[1] = 0, from[1] = 0, qq.push(1);
        while(qq.size()) {
            int u = qq.front(); qq.pop();
            for(int v : G[u]) {
                if(dst[u] + 1 < bad[v] && dst[v] == INF) dst[v] = dst[u] + 1, from[v] = u, qq.push(v);
            }
        }

        if(dst[n] < INF || dst[n+n] < INF) {
            if(dst[n] < dst[n+n]) {
                cout << dst[n] << "\n";
                print(from, n, n), cout << "\n";
            }
            else {
                cout << dst[n+n] << "\n";
                print(from, n+n, n), cout << "\n";
            }
        }
        else cout << "-1\n";
    }
    return 0;
}