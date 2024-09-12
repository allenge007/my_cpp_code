#include <bits/stdc++.h>

using namespace std;
#define fir first
#define sec second
const int maxn = 2e5 + 5;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
vector<int> G[maxn];
int n, c[maxn], w[maxn];
unordered_map<int, long long> f[maxn];
long long g[maxn], cha[maxn], ans;
inline void merge(int &x, int &y, long long &cnt, long long sum) {
    if(f[x].size() < f[y].size()) swap(f[x], f[y]), swap(cha[x], cha[y]);
    for(auto it : f[y]) {
        if(f[x][it.fir]) cnt = max(cnt, sum + f[x][it.fir] + cha[x] + it.sec + cha[y]);
        if(!f[x][it.fir] || f[x][it.fir] + cha[x] < it.sec + cha[y]) {
            f[x][it.fir] = it.sec + cha[y] - cha[x];
        }
    }
    f[y].clear();
}
void dfs(int x, int fa) {
    long long sum = 0;
    cha[x] = g[x] = 0;
    for(auto it : G[x]) {
        if(it == fa) continue;
        dfs(it, x);
        sum += g[it];
    }
    long long cnt = sum;
    for(auto it : G[x]) {
        if(it == fa) continue;
        cha[it] -= g[it];
        merge(x, it, cnt, sum);
    }
    if(f[x][c[x]]) cnt = max(cnt, sum + cha[x] + f[x][c[x]] + w[x]);
    if(!f[x][c[x]] || f[x][c[x]] + cha[x] < w[x]) f[x][c[x]] = w[x] - cha[x];
    cha[x] += sum, g[x] = cnt, ans = max(ans, cnt);
}
void solve() {
    n = read();
    for(int i = 1; i <= n; i ++) c[i] = read();
    for(int i = 1; i <= n; i ++) w[i] = read();
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y), G[y].push_back(x);
    }
    ans = 0;
    dfs(1, 0);
    printf("%lld\n", ans);
    for(int i = 1; i <= n; i ++) G[i].clear(), f[i].clear();
}
int main() {
    int T;
    T = read();
    while(T --) solve();
    return 0;
}