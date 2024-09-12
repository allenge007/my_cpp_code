#include <bits/stdc++.h>

using namespace std;
const int maxn = 15;
int T, a[maxn], sum[maxn];
void solve() {
    for(int i = 0; i < 9; i ++) cin >> a[i], sum[i] = 0;
    int ans = 0;
    for(int i = 0; i < 9; i ++) {
        if(a[i] == 0) continue;
        for(int j = a[i]; j < 9; j ++)
            sum[j] ++;
        ans += sum[a[i] - 1];
    }
    if(ans % 2 == 0) cout << "Yes\n";
    else cout << "No\n";
}
int main() {
    cin >> T;
    while(T --) solve();
    return 0;
}