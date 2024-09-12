#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
const long long mod = 998244353;
int n;
long long f[maxn], g[maxn];
bool vis[maxn];
int main() {
    scanf("%d", &n);
    f[1] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j + 1 <= n; j += i)
            f[j + 1] += f[i], f[j + 1] %= mod;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j += i)
            g[j] += f[i], g[j] %= mod;
    }
    for(int i = 1; i <= n; i ++) printf("%lld ", g[i]);
    return 0;
}