#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17 + 17;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e3 + 5;
struct node{
    int x, y, val;
}edge[maxn * maxn];
int n, f[maxn], head[maxn], ver[maxn * maxn * 2], Next[maxn * maxn * 2], ev[maxn * maxn * 2], tot, fs[maxn][11], sum[maxn][11];
bool vis[maxn * maxn];
void add(int x, int y, int z) {
    ver[++ tot] = y, ev[tot] = z, Next[tot] = head[x], head[x] = tot;
}
bool cmp(node x, node y) {
    return x.val < y.val;
}
inline int getfa(int x) {
    if(f[x] == x) return x;
    return f[x] = getfa(f[x]);
}
int d[maxn];
void dfs(int x, int fa) {
    for(int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if(y == fa) continue;
        fs[y][0] = x, sum[y][0] = ev[i], d[y] = d[x] + 1;
        for(int j = 1; j <= 10; j ++) sum[y][j] = sum[y][j - 1] + sum[fs[y][j - 1]][j - 1], fs[y][j] = fs[fs[y][j - 1]][j - 1];
        dfs(y, x);
    }
}
int lca(int x, int y) {
	if(d[x] > d[y]) swap(x, y);
    int ans = 0;
	for(int i=10; i>=0; i--) if(d[fs[y][i]] >= d[x]) ans += sum[y][i], y = fs[y][i];
	if(x == y) return ans;
	for(int i=10; i>=0; i--) if(fs[x][i] != fs[y][i]) ans += sum[x][i] + sum[y][i], x = fs[x][i], y = fs[y][i];
	return ans + sum[x][0] + sum[y][0];
}
signed main() {
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n * (n - 1)/ 2; i ++) {
        int x = read(), y = read(), val = read();
        edge[i] = (node){x, y, val}, ans += val;
    }
    return printf("%lld\n", ans), 0;
    sort(edge + 1, edge + n * (n - 1)/ 2 + 1, cmp);
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= n * (n - 1) / 2; i ++) {
        int r1 = getfa(edge[i].x), r2 = getfa(edge[i].y);
        if(r1 != r2) {
            f[r2] = r1;
            vis[i] = 1;
            add(edge[i].x, edge[i].y, edge[i].val);
            add(edge[i].y, edge[i].x, edge[i].val);
        }
    }
    dfs(1, 0);
    return 0;
}