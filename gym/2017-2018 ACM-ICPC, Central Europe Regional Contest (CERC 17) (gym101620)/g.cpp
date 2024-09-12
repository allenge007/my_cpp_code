#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxn = 300005;
int n, m, u, v, deg[maxn], tmp[maxn], vst[maxn];
double f[maxn], sum[maxn];
vector<int> to[maxn];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> u >> v;
		to[u].push_back(v), to[v].push_back(u);
		++deg[u], ++deg[v];
	}
	if(n == 1) return printf("0\n"), 0;
	for(int i = 1; i <= n; ++i) f[i] = 1e108;
	f[n] = 0;
	q.push({0, n});
	while(!q.empty()) {
		int u = q.top().second;
		double exp = q.top().first;
		q.pop();
        if(vst[u]) continue;
        vst[u] = 1;
		for(auto v : to[u]) {
            if(vst[v]) continue;
            tmp[v] ++, sum[v] += f[u];
            if((sum[v] + deg[v]) / tmp[v] < f[v]) {
                f[v] = (sum[v] + deg[v]) / tmp[v];
                q.push({f[v], v});
            }
        }
	}
	cout << fixed << setprecision(10) << f[1] << endl;
    return 0;
}