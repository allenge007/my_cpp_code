#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], b[maxn], c[maxn], B[maxn];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        a[x] ++;
    }
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        b[x] ++, B[i] = x;
    }
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        c[x] ++;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += c[i] * a[B[i]];
        // cout << c[i] << " " << b[i] << " " << a[i] << endl;
    }
    printf("%lld\n", ans);
    return 0;
}