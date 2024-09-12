#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
vector<int> g[maxn], qury[maxn];
int f[maxn][20], deep[maxn], ff[maxn], u[maxn], v[maxn], ans[maxn];
bool vis[maxn];
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -f; ch = getchar();}
    while(isdigit(ch)) w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
void dfs(int x, int fa) {
    f[x][0] = fa, deep[x] = deep[fa] + 1;
    for(int i = 1; i < 20; i ++) f[x][i] = f[f[x][i - 1]][i - 1];
    for(auto it : g[x]) {
        if(it == fa) continue;
        dfs(it, x);
    }
}
int lca(int x, int y){
	if(deep[x] > deep[y]) swap(x, y);
	for(int i=19; i>=0; i--) if(deep[f[y][i]] >= deep[x]) y = f[y][i];
	if(x == y) return x;
	for(int i=19; i>=0; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
int getfa(int x) {
    if(ff[x] == x) return x;
    return ff[x] = getfa(ff[x]);
}
int getl(int x, int y) {
    return deep[x] + deep[y] - 2 * deep[lca(x, y)];
}
void merge(int x, int y) {
    int r1 = getfa(ff[x]), r2 = getfa(ff[y]);
    if(r1 == r2) return ;
    if(deep[r1] > deep[r2]) swap(r1, r2), swap(x, y);
    x = r1, y = r2;
    ff[r2] = r1;
    int t1 = u[x], t2 = v[x], t3 = u[y], t4 = v[y];
    int l1 = getl(u[x], v[x]), l2 = getl(u[y], v[y]), l3 = getl(u[x], u[y]), l4 = getl(v[x], v[y]);
    int maxi = max(max(l1, l2), max(l3, l4));
    if(maxi == l1) {
        u[r1] = t1, v[r1] = t2;
    }
    else if(maxi == l2) {
        u[r1] = t3, v[r1] = t4;
    }
    else if(maxi == l3) {
        u[r1] = t1, v[r1] = t3;
    }
    else {
        u[r1] = t2, v[r1] = t4;
    }
}
void Merge(int x, int l, int i) {
    while(deep[getfa(x)] > deep[l]) {
        int fa = f[getfa(x)][0];
        if(!vis[fa]) qury[i].push_back(fa);
        vis[fa] = 1, merge(getfa(x), fa);
        for(auto it : g[fa]) {
            if(vis[it]) merge(fa, it);
        }
        x = fa;
    }
}

void init(int n) {
    for(int i = 1; i <= n; i ++)
        ff[i] = u[i] = v[i] = i;
}

void solve() {
    int n = read(), q = read();
    for(int i = 1; i < n; i ++) {
        int x = read(), y = read();
        g[x].push_back(y), g[y].push_back(x);
    }
    dfs(1, 0);
    init(n);
    for(int i = 1; i <= q; i ++) {
        int x = read(), y = read();
        if(!vis[x]) {
            qury[i].push_back(x), vis[x] = 1;
            for(auto it : g[x]) {
                if(vis[it]) merge(x, it);
            }
        }
        if(!vis[y]) {
            qury[i].push_back(y), vis[y] = 1;
            for(auto it : g[y]) {
                if(vis[it]) merge(y, it);
            }
        }
        int l = lca(x, y);
        Merge(x, l, i);
        Merge(y, l, i);
        ans[i] = max(ans[i - 1], getl(u[getfa(x)], v[getfa(x)]) + 1);
        // cout << "The black length is " <<  ans[i] << endl;
    }
    init(n);
    int w = 0;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            for(auto it : g[i]) {
                if(!vis[it]) merge(i, it);
            }
            w = max(w, getl(u[getfa(i)], v[getfa(i)]));
        }
    }
    ans[q] = max(ans[q], w + 1);
    for(int i = q; i >= 2; i --) {
        for(auto it : qury[i]) {
            vis[it] = 0;
            for(auto x : g[it]) {
                if(!vis[x]) merge(it, x);
            }
            // cout << it <<" ";
            w = max(w, getl(u[getfa(it)], v[getfa(it)]));
        }
        ans[i - 1] = max(ans[i - 1], w + 1);
        // cout << "The " << i <<"th white length is" << w << endl;
    }
    // for(int i = 1; i <= n; i ++) cout << vis[i] << " ";
    // cout << endl;
    for(int i = 1; i <= q; i ++) printf("%d\n", ans[i]);
    for(int i = 1; i <= q; i ++) ans[i] = 0, qury[i].clear();
    for(int i = 1; i <= n; i ++) {
        g[i].clear(), vis[i] = 0, deep[i] = 0;
        for(int j = 0; j < 20; j ++)
            f[i][j] = 0;
    }
}
int main() {
    // std :: ios :: sync_with_stdio(false);
    int T = read();
    while(T --) solve();
    return 0;
}