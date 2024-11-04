#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int a[maxn];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 2; i <= n; i ++)
        if(abs(a[i] - a[i - 1]) == 5 || abs(a[i] - a[i - 1]) == 7) ;
        else return cout << "NO\n", void();
    cout << "YES\n";
}
int main() {
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}