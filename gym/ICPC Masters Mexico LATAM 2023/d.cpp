#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int R, C, K, a[maxn];
int main() {
    scanf("%d%d%d", &R, &C, &K);
    for(int i = 1; i <= C; i ++) {
        int x;
        scanf("%d", &x);
        a[x] ++;
    }
    sort(a + 1, a + R + 1, [](int x, int y) {
        return x > y;
    });
    int ans = 0;
    for(int i = 1; i <= K; i ++) ans += a[i];
    printf("%d\n", ans);
    return 0;
}