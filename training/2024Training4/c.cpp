#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, INF = 1e9;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
int n, k, a[maxn], prime[maxn/10], tot;
bool vis[maxn];
inline bool check(int x) {
    set<pair<int, int>> s;
    int sum = 0, cnt = 0;
    for(register int i = 1; i <= n; i ++) {
        bool flag = 0;
        for(auto [val, j] : s) {
            if(!vis[i - j] && sum + a[i] - val >= x) {
                cnt ++, s.clear(), flag = 1;
                break;
            }
            else if(sum + a[i] - val < x) break;
        }
        if(!flag) s.insert({sum, i - 1});
        sum += a[i];
        if(cnt >= k) return 1;
    }
    return cnt >= k;
}
inline void solve() {
    n = read(), k = read();
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i ++) {
        a[i] = read();
        if(a[i] < 0) sum1 += a[i];
        else sum2 += a[i];
    }
    if(2 * k > n) return puts("impossible"), void();
    // cout << sum1 << " " << sum2 << endl;
    int l = sum1, r = sum2;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", r);
}
int main() {
    for(int i = 2; i <= 200000; i ++) {
        if(!vis[i]) prime[++ tot] = i;
        for(int j = 1; j <= tot && i * prime[j] <= 200000; j ++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    int T;
    T = read();
    while(T --) solve();
    return 0;
}