#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define fir first
#define sec second
const int maxn = 250005;
int a[maxn], b[maxn];
pair<int, int> c[maxn];
bool vis[maxn];
void solve() {
    int n, q;
    long long ans = 0;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i ++) a[i] = read(), ans += a[i];
    for(int i = 0; i < n; i ++) b[i] = read();
    // cout << ans << endl;
    int t = 3000;
    for(int i = 1; i <= min(q, t); i ++) {
        int x = read();
        if(vis[x]) {
            printf("%lld\n", ans);
            continue;
        }
        vis[x] = 1;
        for(int j = 0; j < n; j ++) {
            ans += max(a[j], b[j + x >= n ? j + x - n : j + x]) - a[j];
            a[j] = max(a[j], b[j + x >= n ? j + x - n : j + x]);
            // cout << a[j] << " ";
        }
        // cout << endl;
        printf("%lld\n", ans);
    }
    if(q > t) {
        for(int i = 0; i < n; i ++) c[i] = {b[i], i};
        sort(c, c + n, [](pair<int, int> x, pair<int, int> y) {
            return x.first > y.first;
        });
        for(int i = 1; i <= q - t; i ++) {
            int x = read();
            if(vis[x]) {
                printf("%lld\n", ans);
                continue;
            }
            vis[x] = 1;
            for(int j = 0; j < min(t, n); j ++) {
                int pos = c[j].sec - x < 0 ? c[j].sec - x + n : c[j].sec - x;
                ans += max(a[pos], c[j].fir) - a[pos];
                a[pos] = max(a[pos], c[j].fir);
            }
            printf("%lld\n", ans);
        }
    }
    for(int i = 0; i < n; i ++) vis[i] = 0;
}
int main() {
    int T;
    T = read();
    while(T --) solve();
    return 0;
}