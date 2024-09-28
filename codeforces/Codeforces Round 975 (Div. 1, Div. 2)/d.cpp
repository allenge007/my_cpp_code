#include <bits/stdc++.h>

using namespace std;
const int maxn =2e5 + 5;
int a[maxn], l[maxn], r[maxn], c[maxn], n;
void add(int x, int k) {
    for(; x <= n + 1; x += x & -x) c[x] += k;
}
int ask(int x) {
    int cnt = 0;
    for(; x; x -= x & -x) cnt += c[x];
    return cnt;
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n + 1; i ++) l[i] = n + 1, r[i] = 0, c[i] = 0;
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
    int mini = n + 1, maxi = 0, ans = 0, cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(!r[i]) continue;
        mini = min(mini, l[i]), maxi = max(maxi, r[i]), ++ cnt;
        add(max(maxi - i + 1, 1), 1), add(min(mini + i - 1, n) + 1, -1);
        if(maxi - mini + 1 > i) return printf("0\n"), void();
    }
    for(int i = 1; i <= n; i ++) if(ask(i) == cnt) ans ++;
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}