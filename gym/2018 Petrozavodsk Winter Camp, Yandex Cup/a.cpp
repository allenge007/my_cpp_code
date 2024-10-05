#include <bits/stdc++.h>

using namespace std;
const int maxn = 105, maxm = 105;
int ord[maxn], sa[maxn], ua[maxn], f[maxn][maxm][maxm], n, s, las[maxn], app[maxn];
bool vis[maxn][maxm][maxm];
inline int bitcnt(int x) {
    int cnt = 0;
    while(x) x -= x & -x, cnt ++;
    return cnt;
}
void output(int i, int j, int k, int f) {
    cout << i << " ";
    for(int l = 0; l < n; l ++) cout << ((j >> l) & 1);
    cout << " ";
    for(int l = 0; l < n; l ++) cout << ((k >> l) & 1);
    cout << " " << f << endl;
}
int dfs(int pos, int s1, int s2) {
    if(pos > 2 * n * (s + 1)) return 0;
    if(vis[pos][s1][s2]) return f[pos][s1][s2];
    vis[pos][s1][s2] = 1;
    int tu = bitcnt(s1) + bitcnt(s2), ta = pos - 1 - tu;
    if(ord[pos] <= n) {
        int news1 = s1 | (1 << (ord[pos] - 1));
        if(news1 == s1) {
            return f[pos][s1][s2] = sa[ta + 1] + dfs(pos + 1, s1, s2);
        } else {
            if(las[pos]) return f[pos][s1][s2] = ua[tu + 1] +  dfs(pos + 1, news1, s2);
            return f[pos][s1][s2] = max(ua[tu + 1] + dfs(pos + 1, news1, s2), sa[ta + 1] + dfs(pos + 1, s1, s2));
        }
    } else {
        int news2 = s2 | (1 << (ord[pos] - n - 1));
        if(news2 == s2) {
            return f[pos][s1][s2] = -sa[ta + 1] + dfs(pos + 1, s1, s2);
        } else {
            if(las[pos]) return f[pos][s1][s2] = -ua[tu + 1] +  dfs(pos + 1, s1, news2);
            return f[pos][s1][s2] = min(-ua[tu + 1] + dfs(pos + 1, s1, news2), -sa[ta + 1] + dfs(pos + 1, s1, s2));
        }
    }
}
int main() {
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= 2 * n * (s + 1); i ++)
        scanf("%d", &ord[i]);
    for(int i = 1; i <= 2 * n * (s + 1); i ++) {
        app[ord[i]] ++;
        if(app[ord[i]] == s + 1) las[i] = 1;
    }
    int ps, pu;
    scanf("%d", &ps);
    for(int i = 1; i <= ps; i ++)
        scanf("%d", &sa[i]);
    scanf("%d", &pu);
    for(int i = 1; i <= pu; i ++)
        scanf("%d", &ua[i]);
    sort(sa + 1, sa + ps + 1, [](int a, int b) { return a > b; });
    sort(ua + 1, ua + pu + 1, [](int a, int b) { return a > b; });
    printf("%d\n", dfs(1, 0, 0));
    return 0;
}