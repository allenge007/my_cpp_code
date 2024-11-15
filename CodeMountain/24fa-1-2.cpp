#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int h[maxn][maxn], a[maxn][maxn], b[maxn][maxn], n, m, hei[maxn][maxn], s[maxn], l[maxn], r[maxn];
bool vis[maxn][maxn];
signed main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) scanf("%lld", &h[i][j]);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            a[i][j] = h[i][j] - h[i][j - 1];
            b[i][j] = h[i][j] - h[i - 1][j];
        }
    }
    for(int i = 2; i <= n; i ++) {
        for(int j = 2; j <= m; j ++) {
            bool flag = 1;
            if(a[i][j] <= a[i - 1][j]) flag &= 1;
            else flag = 0;
            if(b[i][j] <= b[i][j - 1]) flag &= 1;
            else flag = 0;
            vis[i][j] = flag;
        }
    }
    int ans = 0;
    for(int i = n; i >= 1; i --) {
        for(int j = 1; j <= m; j ++) {
            if(vis[i][j]) hei[i][j] = hei[i + 1][j] + vis[i][j];
        }
        int tot = 0;
        s[0] = 0;
        for(int j = 1; j <= m; j ++) {
            while(tot && hei[i][s[tot]] >= hei[i][j]) tot --;
            l[j] = s[tot];
            s[++ tot] = j;
        }
        tot = 0;
        s[0] = m + 1;
        for(int j = m; j >= 1; j --) {
            while(tot && hei[i][s[tot]] >= hei[i][j]) tot --;
            r[j] = s[tot];
            s[++ tot] = j;
        }
        for(int j = 1; j <= m; j ++) {
            if(hei[i][j]) ans = max(ans, (r[j] - l[j]) * (hei[i][j] + 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}