#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 3233;
long long qpow(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if(N & 1) {
        if(N == 1) cout << 3 << endl;
        else {
            cout << 3 * qpow(2, N - 1) % mod << endl;
        }
    } else {
        cout << 3 * qpow(2, N - 2) % mod << endl;
    }
    return 0;
}