#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n;
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    long long ans = 0, k = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == 1 && a[i] < a[i - 1]) return printf("-1\n"), void();
        if(a[i] == 1) continue;
        if(i > 1 && a[i - 1] > 1) {
            k += ceil(log2(fabs(log(a[i - 1])/log(a[i]))));
            k = max(k, 0ll);
            ans += k;
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