#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int n, a[maxn];
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int fir = 0, sec = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i ++) {
        if(!fir) fir = a[i];
        else if(fir and !sec and a[i] != fir) sec = a[i];
        if(a[i] == fir) cnt1 ++;
        else if(a[i] == sec) cnt2 ++;
    }
    if(cnt1 + cnt2 != n) return printf("No\n"), void();
    if(cnt2 == 0) return printf("Yes\n"), void();
    if(abs(cnt1 - cnt2) > 1) return printf("No\n"), void();
    printf("Yes\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --)
        solve();
    return 0;
}