#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w*f;
}
const int maxn = 55;
int a[maxn], b[maxn], n, m, k, T;
signed main() {
    T = read();
    while(T --) {
        scanf("%lld%lld%lld", &n, &m, &k);
        int s1 = 0, s2 = 0;
        for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]), s1 += a[i];
        for(int i = 1; i <= m; i ++) scanf("%lld", &b[i]), s2 += b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        if(a[1] >= b[m]) {
            if(k & 1) printf("%lld\n", s1);
            else printf("%lld\n", s1 - a[n] + b[1]);
        }
        else if(a[n] <= b[1]) {
            if(k & 1) printf("%lld\n", s1 - a[1] + b[m]);
            else printf("%lld\n", s1);
        }
        else {
            int maxi = max(a[n], b[m]), mini = min(a[1], b[1]);
            if(k == 1) printf("%lld\n", s1 - a[1] + b[m]);
            else {
                if(k & 1) printf("%lld\n", s1 - a[1] + b[m]);
                else printf("%lld\n", s1 - a[1] + b[m] - maxi + mini);
            }
        }
    }
    return 0;
}