#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e5 + 5;
const long long mod = 1e9 + 7;
int n, s[maxn], t[maxn];
long long f[2][maxn][4];
long long qpow(long long x, int long y) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
long long dfs(int p, int i, int to) {
    if(!i) return 0;
    if(f[p][i][to]) return f[p][i][to];
    if(p == 0) {
        if(s[i] == to) return f[p][i][to] = dfs(p, i - 1, to);
        return f[p][i][to] = (dfs(p, i - 1, 6 - s[i] - to) + qpow(2ll, i - 1)) % mod;
    }
    if(t[i] == to) return f[p][i][to] = dfs(p, i - 1, to);
    return f[p][i][to] = (dfs(p, i - 1, 6 - t[i] - to) + qpow(2ll, i - 1)) % mod;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &s[i]);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &t[i]);
    long long k = 0;
    for(int i = n; i >= 1; i --) {
        if(s[i] != t[i]) {
            k = i;
            break;
        }
    }
    if(k == 0) return printf("0\n"), 0;
    printf("%lld\n", (dfs(0, k - 1, 6 - s[k] - t[k]) + dfs(1, k - 1, 6 - s[k] - t[k]) + 1) % mod);
    return 0;
}