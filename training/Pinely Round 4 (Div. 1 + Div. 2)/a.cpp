#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int a[maxn];
void solve() {
    int n, maxi = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i += 2) maxi = max(maxi, a[i]);
    printf("%d\n", maxi);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}