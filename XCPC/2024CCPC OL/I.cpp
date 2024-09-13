#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;
const int N = 510;

inline ll add(ll & x, ll y) {
    x += y;
    if (x >= mod) x -= mod; 
    return x;
}

ll f[N][N], g[N];

int cnta[N];
int n, m, a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        cnta[a[i]]++;
    }
    sort(b + 1, b + 1 + m);
    mx = max(mx, b[m]);

    for (int i = 1; i <= mx; i++) cnta[i] += cnta[i - 1];

    for (int t = 0; t <= mx; t++) {
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = 0;
        f[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            int x = 0;
            if (i == 1 || (i > 1 && b[i - 1] < b[i]))
                x = (b[i] - t - 1 > 0 ? cnta[b[i] - t - 1] : 0) - (b[i - 1] - t - 1 > 0 ? cnta[b[i - 1] - t - 1] : 0);
            for (int j = 0; j <= n; j++) {
                add(f[i][j + x - 1], f[i - 1][j] * (j + x) % mod);
                add(f[i][j + x], f[i - 1][j]);
            }
        }
        for (int j = 0; j <= n; j++)
           add(g[t], f[m][j]);
        // cout << g[t] << endl;
    }

    ll ans = 0;
    for (int i = 1; i <= mx; i++)
        add(ans, (g[i - 1] - g[i] + mod) % mod * i % mod);
    cout << ans << endl;

    return 0;
}