#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e5 + 5;
void solve() {
    int n = read(), m = read(), a = read(), b = read(), c = read(), d = read();
    if(a > c) swap(a, c), swap(b, d);
    else if(a == c && b < d) swap(b, d);
    if(b > d) m -= (d - c) * n, b -= d - c, c = a, d = c;
    else if(b > c) m -= (b - c) * n, d -= b - c, b = c;
    if(m <= 0) return printf("0\n"), void();
    int x = max(a, c) - min(a, c) + max(b, d) - min(b, d);
    int y = max(b, d) - min(a, c);
    int x2 = 0, y2 = 0, ans = 0;
    if(y) {
        y2 = min(m/y, n), x2 = m - y2 * y;
        ans=min(y2?x*y2+x2*2:1000000000000000000ll,(y2<n&&x2<y)?x*(y2+1)-(y-x2):100000000000000000ll);
    }
    else ans = m * 2;
    return printf("%lld\n", ans), void();
}
signed main() {
    int T = read();
    while(T --) solve();
    return 0;
}