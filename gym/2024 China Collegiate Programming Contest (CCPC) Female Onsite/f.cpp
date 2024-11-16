#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5, INF = 1e6;
const long long mod = 1e9 + 7;
int n, a[maxn], prime[maxn], vis[maxn], cnt, id[maxn], sum[maxn];
long long f[maxn][2], p[maxn][2];
vector<int> fac[maxn];
void get_prime() {
    for(int i = 2; i <= INF; i ++) {
        if(!vis[i]) prime[++ cnt] = i, id[i] = cnt, vis[i] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= INF; j ++) {
            vis[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}
inline long long qpow(long long a, long long b) {
    long long res = 1;
    for(; b; b >>= 1, a = a * a % mod) if(b & 1) res = res * a % mod;
    return res;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    get_prime();
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        while(x > 1) {
            int p = vis[x], num = 0;
            while(x % p == 0) x /= p, num ++;
            fac[id[p]].push_back(num);
        }
    }
    long long ans = 1;
    for(int i = 1; i <= cnt; i ++) {
        if(fac[i].empty()) continue;
        int m = fac[i].size(), maxi = 0;
        for(int j = 0; j < m; j ++) {
            maxi = max(maxi, fac[i][j]);
        }
        p[0][0] = 1, p[0][1] = 0;
        for(int j = 1; j <= maxi; j ++) {
            p[j][1] = p[j - 1][1], p[j][0] = p[j - 1][0];
            if(j & 1) p[j][1] += qpow(prime[i], j / 2), p[j][1] %= mod;
            else p[j][0] += qpow(prime[i], j / 2), p[j][0] %= mod;
        }
        for(int j = 0; j <= m; j ++) f[j][0] = f[j][1] = 0;
        f[0][0] = 1;
        for(int j = 0; j < m; j ++) {
            f[j + 1][0] = (f[j][0] * p[fac[i][j]][0] % mod + f[j][1] * p[fac[i][j]][1] * prime[i] % mod) % mod;
            f[j + 1][1] = (f[j][0] * p[fac[i][j]][1] % mod + f[j][1] * p[fac[i][j]][0] % mod) % mod;
        }
        ans = ans * f[m][0] % mod;
    }
    cout << (ans + mod) % mod << endl;
    return 0;
}