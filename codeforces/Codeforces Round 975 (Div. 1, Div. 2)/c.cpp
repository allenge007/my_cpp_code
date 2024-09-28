#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], n, k, maxi, sum;
void solve() {
    scanf("%lld%lld", &n, &k);
    sum = 0, maxi = 0;
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), maxi = max(maxi, a[i]), sum += a[i];
    for(int i = n; i >= 1; i --) {
        if((sum + k) % i <= k && (sum + k) / i >= maxi) return printf("%d\n", i), void();
    }
    return ;
}
int main() {
    int T;
    scanf("%d" ,&T);
    while(T --) solve();
    return 0;
}