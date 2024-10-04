#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int p[maxn], q[maxn], vis[maxn], ans[maxn];
void solve() {
    int n, tot = 0, mini;
    scanf("%d", &n);
    mini = n + 1;
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]), vis[i] = 0, ans[i] = 0;
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        int sum = 1;
        vis[i] = 1;
        int now = p[i];
        while(!vis[now]) vis[now] = 1, now = p[now], sum ++;
        if(sum < mini) {
            mini = sum, tot = 0;
            now = p[i], q[++ tot] = i;
            while(now != i) q[++ tot] = now, now = p[now];
        }
    }
    if(tot == n) {
        if(tot == 2) return printf("0\n1\n1\n"), void();
        printf("%d\n", tot - 2);
        swap(p[1], p[2]);
        for(int i = 1; i <= n; i ++) vis[i] = 0, ans[i] = 0;
        for(int i = 1; i <= n; i ++) {
            if(vis[i]) continue;
            int sum = 1;
            vis[i] = 1;
            int now = p[i];
            while(!vis[now]) vis[now] = 1, now = p[now], sum ++;
            mini = sum, tot = 0;
            now = p[i], q[++ tot] = i;
            while(now != i) q[++ tot] = now, now = p[now];
            break;
        }
        printf("%d\n", tot);
        q[1] = 2;
        sort(q + 1, q + tot + 1);
        for(int i = 1; i <= tot; i ++) printf("%d ", q[i]);
        puts("");
        return ;
    }
    printf("%d\n", n);
    printf("%d\n", tot);
    sort(q + 1, q + tot + 1);
    for(int i = 1; i <= tot; i ++) printf("%d ", q[i]);
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}