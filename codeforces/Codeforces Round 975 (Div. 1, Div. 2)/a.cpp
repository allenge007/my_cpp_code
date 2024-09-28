#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int a[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int maxi1 = 0, cnt1 = 0, maxi2 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i += 2) {
        cnt1 ++;
        maxi1 = max(maxi1, a[i]);
    }
    for(int i = 2; i <= n; i += 2) {
        cnt2 ++;
        maxi2 = max(maxi2, a[i]);
    }
    printf("%d\n", max(cnt1 + maxi1, cnt2 + maxi2));
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}