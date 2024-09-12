#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

const int N = 110;

int n, m;
char s[N], t[N];

ll f[2][N][N];

int main() {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= m; i++)
        if (t[i] == s[1]) f[1][i][i] = 1;
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= m; j++) printf("%lld ", f[1][i][j]);
    //     puts("");
    // }
    for (int x = 2; x <= n; x++) {
        int cur = (x & 1);
        for (int i = 1; i <= m; i++)
            for (int j = i; j <= m; j++) f[cur][i][j] = f[cur ^ 1][i][j] * 2ll % mod;
        for (int k = 1; k <= m; k++)
            if (s[x] == t[k]) {
                f[cur][k][k]++;
                for (int i = 1; i < k; i++)
                    (f[cur][i][k] += f[cur ^ 1][i][k - 1]) %= mod;
                for (int j = k + 1; j <= m; j++)
                    (f[cur][k][j] += f[cur ^ 1][k + 1][j]) %= mod;
                for (int i = 1; i < k; i++)
                    for (int j = k + 1; j <= m; j++)
                        f[cur][i][j] = (f[cur][i][j] + f[cur ^ 1][i][k - 1] * f[cur ^ 1][k + 1][j] % mod) % mod;
            }
        for (int i = 1; i <= m; i++)
            for (int j = i; j <= m; j++)
                for (int k = i; k < j; k++)
                    f[cur][i][j] = (f[cur][i][j] + f[cur ^ 1][i][k] * f[cur ^ 1][k + 1][j] % mod) % mod;
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= m; j++) printf("%lld ", f[cur][i][j]);
        //     puts("");
        // }
    }
    int cur = n & 1;
    printf("%lld\n", f[cur][1][m] % mod);
    return 0;
}