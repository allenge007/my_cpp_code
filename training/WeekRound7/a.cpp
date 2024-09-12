#include <bits/stdc++.h>

using namespace std;
const long long mod = 10007;
int n;
long long qpow(long long x, long long y) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % mod;
        basic = basic * basic % mod, y >>= 1;
    }
    return cnt;
}
int main() {
    cin >> n;
    cout << n * qpow(8, n) % mod;
    return 0;
}