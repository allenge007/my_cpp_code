#include <bits/stdc++.h>

using namespace std;
const int maxn = 505;
const long long mod1 = 19260817, mod2 = 998244353;
int a[maxn], n;
pair<long long, long long> Hash;
map<pair<long long, long long>, bool> vis;
int main() {
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= 500; i ++) {
        Hash.first = Hash.second = 0;
        for(int j = 1; j <= n; j ++) {
            Hash.first = (Hash.first * 131 + a[j] % i) % mod1;
            Hash.second = (Hash.second * 233 + a[j] % i) % mod2;
        }
        if(vis[Hash] == 0) {
            vis[Hash] = 1;
            ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}