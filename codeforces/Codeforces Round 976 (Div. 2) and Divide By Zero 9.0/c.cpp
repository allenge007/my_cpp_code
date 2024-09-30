#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long b, c, d, ans = 0;
    long long B, C;
    scanf("%lld%lld%lld", &b, &c, &d);
    B = b, C = c;
    for(int i = 0; i <= 62; i ++) {
        if((d >> i) & 1) {
            if((c >> i)&1 && !((b >> i)&1)) return printf("-1\n"), void();
            else if((c >> i)&1 && (b >> i)&1) c -= 1ll << i, b -= 1ll << i, d -= 1ll << i;
            else if((b >> i)&1) b -= 1ll << i, d -= 1ll << i;
            else ans += 1ll << i, d -= 1ll << i;
        } else {
            if((c >> i)&1 && (b >> i)&1) c -= 1ll << i, b -= 1ll << i, ans += 1ll << i;
            else if((c >> i)&1 && !((b >> i)&1)) c -= 1ll << i;
            else if((b >> i)&1) return printf("-1\n"), void();
        }
        if(b < 0 || c < 0) return printf("-1\n"), void();
    }
    if(d) return printf("-1\n"), void();
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}