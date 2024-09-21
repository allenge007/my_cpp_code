#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
struct node{
    long long w, v, c;
    node(long long w = 0, long long v = 0, long long c = 0) : w(w), v(v), c(c) {};
}a[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        long long x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        a[i] = node(x, y, z);
    }
    sort(a + 1, a + n + 1, [](node x, node y) {
        return x.c * y.w < y.c * x.w;
    });
    long long ans = 0, W = 0;
    for(int i = 1; i <= n; i ++) ans += a[i].v - a[i].c * W, W += a[i].w;
    printf("%lld\n", ans);
    return 0;
}