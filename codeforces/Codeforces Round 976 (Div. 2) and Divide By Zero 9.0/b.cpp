#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long k;
    scanf("%lld", &k);
    long long x = floor(sqrt(k));
    long long n = k + x;
    while(n >= (x + 1) * (x + 1)) {
        x ++, n ++;
    }
    printf("%lld\n", n);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}