#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
void solve(long long x) {
    assert(x > 0);
    if(x == 1) return ;
    if(x & 1) {
        ans += x + 1;
        solve(x + x / 2 + 1);
    }
    else {
        ans += x;
        solve(x / 2);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    printf("%lld\n", ans);
    return 0;
}