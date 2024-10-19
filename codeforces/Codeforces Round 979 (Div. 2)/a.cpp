#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int a[maxn], n;
void solve() {
    scanf("%d", &n);
    int mini = 1001, maxi = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), mini = min(mini, a[i]), maxi = max(maxi, a[i]);
    if(n <= 1) return printf("0\n"), void();
    printf("%d\n", (maxi - mini) * (n - 1));
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}