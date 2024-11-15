#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, maxm = 1e6 + 5;
int n, a[maxn], las[maxm], pre[maxn];
long long sum[maxn], f[maxn][2];
void solve() {
    scanf("%d", &n);
    int maxi = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        maxi = max(maxi, a[i]);
        sum[i] = sum[i - 1];
        if(a[i] == a[i - 1]) sum[i] += a[i];
        pre[i] = las[a[i]];
        las[a[i]] = i;
    }
    for(int i = 1; i <= n; i ++) f[i][0] = f[i][1] = 0;
    for(int i = 1; i <= n; i ++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        if(pre[i]) f[i][1] = max(f[pre[i] + 1][1], f[pre[i] + 1][0]) + sum[i - 1] - sum[pre[i]] + a[i];
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    for(int i = 0; i <= maxi; i ++) las[i] = 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}