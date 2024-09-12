#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 5;
char str[maxn];
int sum[20];
bool vis[maxn];
int popcnt(int x) {
    int cnt = 0;
    while(x) x -= x & (-x), cnt ++;
    return cnt;
}
void solve() {
    int n, c, k, all, ans, st = 0;
    scanf("%d%d%d%s", &n, &c, &k, str);
    all = (1 << c) - 1;
    for(int i = 0; i < c; i ++) sum[i] = 0;
    for(int i = 0; i < k; i ++) {
       sum[str[i] - 'A'] ++;
    }
    // cout << "fuck" << endl;
    for(int i = 0; i < c; i ++) if(sum[i]) st |= 1 << i;
    for(int i = 0; i < (1 << c); i ++) vis[i] = 0;
    vis[st ^ all] = 1;
    for(int i = 1; i < n - k + 1; i ++) {
        sum[str[i - 1] - 'A'] --;
        if(!sum[str[i - 1] - 'A']) st ^= 1 << (str[i - 1] - 'A');
        sum[str[i + k - 1] - 'A'] ++;
        if(sum[str[i + k - 1] - 'A'] == 1) st ^= 1 << (str[i + k - 1] - 'A');
        vis[st ^ all] = 1;
    }
    for(int i = 0; i < (1 << c); i ++) {
        if(vis[i]) {
            for(int j = i; j; j = i & (j - 1)) {
                vis[j] = 1;
            }
        }
    }
    ans = c;
    for(int i = 1; i < (1 << c); i ++) {
        if(!vis[i] && (i & (1 << str[n - 1] - 'A'))) {
            ans = min(ans, popcnt(i));
        }
    }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}