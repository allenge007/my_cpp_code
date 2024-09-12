#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], sum[maxn];
void solve() {
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
    long long tmp = a[1];
    int p = 1;
    for(int i = 2; i <= n; i ++) {
        if(tmp + a[i] >= (1ll * i) * c) {
            tmp = sum[i];
            p = i;
        }
    }
    if(p == n) printf("yes\n");
    else printf("no\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}