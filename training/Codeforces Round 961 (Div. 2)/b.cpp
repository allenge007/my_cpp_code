#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], c[maxn];
long long m;
void solve() {
    int n;
    map<int, long long> S;
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &c[i]), S[a[i]] += c[i];
    int las = 0;
    long long lasnum = 0;
    long long ans = 0;
    for(auto it = S.begin(); it != S.end(); ++ it) {
        if(it == S.begin()) {
            las = it -> first, lasnum = it -> second;
            long long lim = m/(it -> first), lft = 0;
            lft = m - (long long)(it -> first) * min(lim, (long long)(it -> second));   
            ans = max(ans, m - lft);
        }
        else {
            if(las + 1 == it -> first) {
                long long lim = m/las, lft = 0, use = 0;
                lft = m - (long long)las * min(lim, (long long)lasnum);
                use = min(lim, (long long)lasnum);
                lim = lft / (it -> first);
                lft = lft - (long long)(it -> first) * min((long long)(it -> second), lim);
                lft = max(0ll, lft - min(it -> second - min((long long)(it -> second), lim), use));
                ans = max(ans, m - lft);
            }
            long long lim = m/(it -> first), lft = 0;
            lft = m - (long long)(it -> first) * min(lim, (long long)(it -> second));
            ans = max(ans, m - lft);
            las = it -> first, lasnum = it -> second;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}