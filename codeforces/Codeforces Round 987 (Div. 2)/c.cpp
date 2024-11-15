#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], tot;
void solve() {
    int n;
    cin >> n;
    if(n % 2 == 0) {
        for(int i = 1, j = 1; i <= n; i += 2, j ++) cout << j << " " << j << " ";
        cout << endl;
        return ;
    }
    if(n <= 26) return cout << -1 << endl, void();
    for(int i = 1; i <= n; i ++) a[i] = 0;
    a[1] = a[10] = a[26] = 1;
    a[23] = a[27] = 2;
    tot = 2;
    for(int i = 1, j = 3; i <= n - 3; i += 2, j ++) {
        while(a[tot]) tot ++;
        a[tot] = j;
        while(a[tot]) tot ++;
        a[tot] = j;
    }
    for(int i = 1; i <= n; i ++) cout << a[i] << " ";
    cout << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}