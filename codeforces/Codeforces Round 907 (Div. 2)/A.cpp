#include <bits/stdc++.h>

using namespace std;
const int maxn = 25;
int a[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 0; i <= 4; i ++) {
        if((1 << i) > n) break;
        for(int j = 1; j < (1 << i); j ++) {
            if(a[j + 1] < a[j]) return printf("NO\n"), void();
        }
        for(int j = 1; j <= (1 << i); j ++)
            a[j] = 0;
    }
    for(int i = 1; i < n; i ++)
        if(a[i + 1] < a[i]) return printf("NO\n"), void();
    printf("YES\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}