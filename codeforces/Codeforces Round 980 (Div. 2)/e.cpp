#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], n, k, m1, m2, col[2][maxn], in[2];
vector<int> g1[maxn], g2[maxn];
bool vis[maxn], chk[2][maxn];
void dfs(int x, vector<int> *g, int type = 0) {
    vis[x] = 1;
    for(auto it : g[x]) {
        if(vis[it]) continue;
        col[type][it] = (col[type][x] + 1) % k;
        dfs(it, g, type);
    }
}
int ptr[2][maxn], str[2][maxn << 1], nxt[2][maxn];
void solve() {
    in[0] = in[1] = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) col[0][i] = col[1][i] = 0, g1[i].clear(), g2[i].clear();
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        if(!a[i]) in[0] ++;
    }
    scanf("%d", &m1);
    for(int i = 1; i <= m1; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g1[x].push_back(y);
    }
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    dfs(1, g1);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i ++) {
        if(!b[i]) in[1] ++;
    }
    scanf("%d", &m2);
    for(int i = 1; i <= m2; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g2[x].push_back(y);
    }
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    dfs(1, g2, 1);
    for(int i = 0; i <= k; i ++) chk[0][i] = chk[1][i] = 0;
    if(in[1] + in[0] != n) return printf("No\n"), void();
    if(!in[1] || !in[0]) return printf("Yes\n"), void();
    auto kmp = [=](int type = 0) {
        for(int i = 0; i <= k; i ++) nxt[type][i] = 0;
        for(int i = 2, j = 0; i <= k; i ++) {
            while(j && ptr[type][j + 1] != ptr[type][i]) j = nxt[type][j];
            if(ptr[type][j + 1] == ptr[type][i]) j ++;
            nxt[type][i] = j;
        }
        bool flag = 0;
        for(int i = 1, j = 0; i <= 2 * k; i ++) {
            while(j && ptr[type][j + 1] != str[type ^ 1][i]) j = nxt[type][j];
            if(ptr[type][j + 1] == str[type ^ 1][i]) j ++;
            if(j == k) {
                flag = 1;
                chk[type][(i - j) % k] = 1;
                j = nxt[type][j];
            }
        }
        return flag;
    };
    for(int i = 1; i <= k; i ++) ptr[0][i] = ptr[1][i] = str[0][i] = str[1][i] = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i]) ptr[0][col[0][i] + 1] ++;
        if(!a[i]) str[0][col[0][i] + 1] ++;
        if(b[i]) ptr[1][col[1][i] + 1] ++;
        if(!b[i]) str[1][col[1][i] + 1] ++;
    }
    for(int i = k + 1; i <= 2 * k; i ++) str[1][i] = str[1][i - k], str[0][i] = str[0][i - k];
    if(!kmp()) return printf("No\n"), void();
    if(!kmp(1)) return printf("No\n"), void();
    for(int i = 0; i < k; i ++) {
        if(chk[0][i] && chk[1][(k - i + 2) % k]) return printf("Yes\n"), void();
    }
    printf("No\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}