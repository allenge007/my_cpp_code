#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn], n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    int ans = 0, pa = 0, pb = 0;
    for(int i = 1; i <= n; i ++) {
        pa = max((long long)pa, upper_bound(b + 1, b + n + 1, a[i]) - b);
        if(pa > n) continue;
        pb = max((long long)pb, upper_bound(c + 1, c + n + 1, b[pa]) - c);
        if(pb > n) continue;
        pa ++, pb ++, ans ++;
    }
    printf("%d", ans);
    return 0;
}