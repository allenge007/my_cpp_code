#include <bits/stdc++.h>

using namespace std;
const int maxn = 4005;
const long long INF = 1e18;
long long f[maxn];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i ++) f[i] = INF;
    f[0] = 0;
    for(int i = 1; i <= n; i ++) {
        long long a[4];
        for(int j = 0; j < 4; j ++) scanf("%lld", &a[j]);
        for(int l = min(4 * i, k); l >= 0; l --) {
            for(int j = 0; j < 4; j ++) {
                if(f[l] < INF && l + j + 1 <= k) {
                    f[l + j + 1] = min(f[l + j + 1], f[l] + a[j]);
                }
            }
        }
        // for(int j = 0; j <= k; j ++) cout << f[j] << " ";
        // cout << endl;
    }
    printf("%lld\n", f[k]);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}