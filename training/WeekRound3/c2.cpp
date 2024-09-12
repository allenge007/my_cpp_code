#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e5 + 5, mod = 1e9 + 7;
int n, m, x[maxn], y[maxn], uni[maxn], tot, f[maxn], c[maxn], cnt;
pair<int, int> p[maxn];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return ((a.first < b.first) || ((a.first == b.first) && (a.second > b.second)));
}
void add(int x, int k) {
    for(; x <= cnt; x += x & -x) {
        c[x] += k, c[x] %= mod;
    }
}
int ask(int i) {
    int ans = 0;
    for(; i; i -= i & -i)
        ans += c[i], ans %= mod;
    return ans;
}   
signed main(){
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%lld", &x[i]);
    for(int j = 1; j <= m; j ++) scanf("%lld", &y[j]);
    for(int i = 1; i <= n; i ++) {
        if(x[i] > y[1] and x[i] < y[m]) {
            int pos = lower_bound(y + 1, y + m + 1, x[i]) - y;
            if(x[i] == y[pos]) continue;
            p[++ tot] = {x[i] - y[pos - 1], y[pos] - x[i]};
            uni[tot] = y[pos] - x[i];
        }
    }
    sort(uni + 1, uni + tot + 1);
    cnt = unique(uni + 1, uni + tot + 1) - uni - 1;
    for(int i = 1; i <= tot; i ++) {
        p[i].second = lower_bound(uni + 1, uni + cnt + 1, p[i].second) - uni;
    }
    sort(p + 1, p + tot + 1, cmp);
    tot = unique(p + 1, p + tot + 1) - p - 1;
    long long ans = 1ll;
    for(int i = 1; i <= tot; i ++) {
        f[i] = ask(p[i].second - 1) + 1;
        add(p[i].second, f[i]);
        ans += f[i], ans %= mod;
    }
    printf("%lld", ans);
    return 0;
}