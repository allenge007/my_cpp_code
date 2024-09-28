#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int x[maxn];
void solve() {
    int n, q;
    map<long long, long long> S;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &x[i]);
    long long sum = 0;
    for(int i = 1; i <= n; i ++) {
        S[(long long) i * (n - i)] += (long long)x[i + 1] - (long long)x[i] + 1ll;
        // if(i * (n - i) == 6) cout << x[i + 1] - x[i] + 1ll << endl, sum += x[i + 1] - x[i] + 1ll;
        S[(long long) (i - 1ll) * (n - i) + (long long)(n - i) + (long long)(i - 1ll)] += 1;
        S[(long long) i * (n - i)] --;
        S[(long long) (i - 1) * (n - i + 1ll)] --;
        // cout << (i * (n - i)) << " " << (i - 1) * (n - i + 1) << endl;
    }
    for(int i = 1; i <= q; i ++) {
        long long k;
        scanf("%lld", &k);
        printf("%lld ", S[k]);
    }
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}