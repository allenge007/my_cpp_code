#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
pair<long long, long long> a[maxn];
int tot;
void solve() {
    long long N;
    scanf("%lld", &N);
    long long cnt = 0;
    for(int i = 1; i <= tot; i ++) {
        if(a[i].second <= N) cnt += a[i].second - a[i].first + 1ll;
        else if(a[i].first > N) break;
        else cnt += N - a[i].first + 1;
    }
    printf("%lld\n", cnt);
}
int main() {
    long long k1 = 1ll, k2 = 1ll;
    a[++ tot] = {1, 1};
    for(int i = 1; i <= 9; i ++) {
        k1 *= 10ll, k2 *= 100ll;
        a[++ tot] = {k2 - 2 * k1, k2 - 2 * k1};
        a[++ tot] = {k2 - k1, k2 + k1 - 1};
    }
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}