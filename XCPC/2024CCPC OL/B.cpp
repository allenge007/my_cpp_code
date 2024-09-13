#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1005;
const int P = 998244353;
int a[N];
i64 fac[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);

    fac[0] = 1;
    for(int i = 1; i <= n; ++i) {
        fac[i] = fac[i-1] * i % P;
    }

    i64 ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            ans += a[j] - a[i];
        }
    }
    i64 num = 1 + (a[1] != a[n]);
    for(int i = 1, j = 2; i <= n; i = j++) {
        while(j <= n && a[j] == a[i]) ++j;
        num *= fac[j-i], num %= P;
    }

    printf("%lld %lld\n", ans, num);
    return 0;
}
