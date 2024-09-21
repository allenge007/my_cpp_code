#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int P = 998244353;

inline i64 binExp(i64 a, i64 b = P - 2, i64 p = P) {
    i64 c = 1;
    while(b) {
        if(b & 1) c = c * a % p;
        a = a * a % p, b >>= 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) {
        int x, y;
        cin >> x >> y;

        i64 a0, a1, b;
        cin >> a0 >> a1 >> b;

        i64 p0 = a0 * binExp(a0 + a1) % P, p1 = a1 * binExp(a0 + a1) % P;

        i64 ans = 0, pp = 1;
        while(x != y) {
            if(x < y) {
                pp = pp * binExp(p0, (y - 1) / x) % P;
                y -= ((y - 1) / x) * x;
            }
            if(x > y) {
                ans += pp * p0 % P * (1 - binExp(p1, (x - 1) / y)) % P * binExp(1 - p1) % P;
                pp = pp * binExp(p1, (x - 1) / y) % P;
                x -= ((x - 1) / y) * y;
            }
        }
        printf("%lld\n", ((ans % P + P) % P + pp * p0 % P) % P);
    }
    return 0;
}