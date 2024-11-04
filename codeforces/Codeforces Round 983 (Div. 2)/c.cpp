#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n;
bool check(int x) {
    int lenth = n - x;
    if(lenth < 3) return 1;
    for(int i = lenth; i <= n; i ++) {
        if(a[i - lenth + 1] + a[i - lenth + 2]  > a[i]) return 1;
    }
    return 0;
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 0, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}