#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
int main() {
    int T;
    cin >> T;
    long long ans = 1ll;
    for(int i = 3; i <= T + 1; i ++) ans = ans * i % mod;
    cout << ans << endl;
    return 0;
}