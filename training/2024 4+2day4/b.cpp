#include <bits/stdc++.h>

using namespace std;
const int maxn = 5005;
const long long mod = 1e9 + 7;
vector<int> g[maxn], num;
int n, siz[maxn], root;
long long fac[maxn], f[maxn][maxn];
void add(int x, int y) {
    g[x].push_back(y), g[y].push_back(x);
}
void dfs(int x, int fa) {
    if(root) return ;
    siz[x] = 1;
    int maxi = 1;
    for(auto it : g[x]) {
        if(root) return ;
        if(it == fa) continue;
        dfs(it, x);
        siz[x] += siz[it];
        maxi = max(maxi, siz[it]);
    }
    maxi = max(maxi, n - siz[x]);
    if(maxi <= n/2) {
        root = x;
        return ;
    }
}
void dfs2(int x, int fa) {
    siz[x] = 1;
    for(auto it : g[x]) {
        if(it == fa) continue;
        dfs2(it, x);
        siz[x] += siz[it];
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    dfs(1, 1);
    dfs2(root, root);
    for(auto it : g[root]) {
        num.push_back(siz[it]);
        cout << siz[it] << " ";
    }
    long long ans = 1, ans2 = 0;
    fac[0] = 1;
    for(int i = 1; i <= n; i ++) fac[i] = fac[i - 1] * i % mod;
    ans = fac[n];
    for(auto it : num) {
        ans2 += fac[it] * fac[n - it] % mod, ans2 %= mod;
    }
    cout << ans2 << endl;
    printf("%lld", ((ans - ans2) % mod + mod) % mod);
    return 0;
}