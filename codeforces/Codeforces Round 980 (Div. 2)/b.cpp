#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
long long sum[maxn], a[maxn], n, k;
void solve() {
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i ++) {
        if(sum[i - 1] + a[i] * (n - i + 1) >= k) {
            printf("%lld\n", i - 1 + k);
            return ;
        }
    }
    // printf("%lld\n", cnt);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}