#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 5;
int N, C, a[maxn];
long long f[maxn], ans, sum;
int main() {
    scanf("%d%d", &N, &C);
    for(int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        if(C <= 0) a[i] = -a[i];
        f[i] = max((long long)a[i], f[i - 1] + a[i]);
        ans = max(ans, f[i]);
        sum += a[i];
    }
    if(C <= 0) printf("%lld\n", -(sum - ans) - ans * C);
    else printf("%lld\n", sum - ans + ans * C);
    return 0;
}