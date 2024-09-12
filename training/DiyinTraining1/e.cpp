#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], sta[maxn];
void solve() {
    int n;
    long long sum = 0;
    map<int, int> S, S2;
    set<int> cnt, cnt2;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        sum += a[i];
        ++ S[a[i]];
        if(S[a[i]] == 2) cnt.insert(a[i]);
        if(!cnt.empty()) a[i] = *cnt.rbegin();
        else a[i] = 0;
    }
    for(int i = 1; i <= n; i ++) {
        sum += a[i];
        ++ S2[a[i]];
        if(S2[a[i]] == 2) cnt2.insert(a[i]);
        if(!cnt2.empty()) a[i] = *cnt2.rbegin();
        else a[i] = 0;
    }
    for(int i = 1; i <= n; i ++) sum += a[i] * (n - i + 1ll);
    printf("%lld\n", sum);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}