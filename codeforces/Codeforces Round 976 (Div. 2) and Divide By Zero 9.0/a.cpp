#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    if(k == 1) return printf("%d\n", n), void();
    while(n) {
        if(n % k) cnt += n % k;
        n /= k;;
    }
    printf("%d\n", cnt);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}