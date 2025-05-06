#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5, maxm = 4e5 + 5, INF = 1e9 + 7;
int N, M, out[maxn], ans[maxn];
vector<int> G[maxn], invG[maxn], val[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        invG[v].push_back(u);
        out[u] ++;
    }
    queue<int> q;
    set<int> S;
    for(int i = 1; i <= N; i++) {
        ans[i] = INF;
        if(out[i] == 0) {
            q.push(i);
            ans[i] = 0;
        } else if(out[i] == 1) {
            S.insert(i);
        }
    }
    while(!q.empty() || !S.empty()) {
        if(q.empty()) {
            bool flag = 0;
			vector<int> tmp;
            for(auto v : S) {
                if(val[v].size()) {
                    sort(val[v].begin(), val[v].end(), greater<int>());
                    ans[v] = val[v][0] + 1;
                    out[v] --;
					tmp.push_back(v);
                    q.push(v);
                    flag = 1;
                }
            }
			for (auto v : tmp) S.erase(v);
			tmp.clear();
            if(!flag) break;
        }
        int u = q.front();
        q.pop();
        for(int v : invG[u]) {
            if(ans[v] != INF) continue;
            out[v] --;
            val[v].push_back(ans[u]);
            if(out[v] == 0) {
                S.erase(v);
                q.push(v);
                if(val[v].size() == 1) {
                    ans[v] = val[v][0] + 1;
                } else {
                    sort(val[v].begin(), val[v].end(), greater<int>());
                    ans[v] = val[v][1] + 1;
                }
            } else if(out[v] == 1) {
                S.insert(v);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(ans[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
