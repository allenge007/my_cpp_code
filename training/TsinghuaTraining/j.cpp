#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
const int maxn = 1005;
unordered_map<int, long long> S, S2;
int n, m, a[maxn][2];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x;
        scanf("%d", &x);
        while(x --) {
            int y;
            scanf("%d", &y);
            if(y > 0) a[y][0] |= (1 << (i - 1));
            else a[-y][1] |= (1 << (i - 1));
        }
    }
    S[0] = 1;
    long long t = 1;
    for(int i = 1; i <= n; i ++) {
        if(a[i][0] == 0 && a[i][1] == 0) {
            t = t * 2 % mod;
            continue;
        }
        for(auto it = S.begin(); it != S.end();) {
            int s = it -> first;
            (S2[s | a[i][0]] += it -> second) %= mod;
            (S2[s | a[i][1]] += it -> second) %= mod;
            it = S.erase(it);
        }
        for(auto it = S2.begin(); it != S2.end(); ) {
            S[it -> first] = it -> second;
            it = S2.erase(it);
        }
    }
    printf("%lld\n", S[(1 << m) - 1] * t % mod);
    return 0;
}