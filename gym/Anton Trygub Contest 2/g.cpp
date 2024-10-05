#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int p[maxn], q[maxn], vis[maxn];
void solve() {
    int n, tot = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]), vis[i] = 0;
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        q[++ tot] = i, vis[i] = 1;
        int now = p[i];
        while(!vis[now]) q[++ tot] = now, vis[now] = 1, now = p[now];
    }
    for(int i = 1; i <= n; i ++) printf("%d ", q[i]);
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}