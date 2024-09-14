#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int b[maxn];
void solve() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    b[++ m] = n + 1;
    for(int i = 1; i <= q; i ++) {
        int x;
        scanf("%d", &x);
        int l = lower_bound(b + 1, b + m + 1, x) - b, r = upper_bound(b + 1, b + m + 1, x) - b;
        if(r == m) {
            printf("%d\n", n - b[r - 1]);
            continue;
        }
        if(b[l] == x) {
            printf("0\n");
            continue;
        }
        if(r == 1) {
            printf("%d\n", b[r] - 1);
        }
        else {
            printf("%d\n", (b[r] - b[l - 1]) / 2);
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}