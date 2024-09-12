#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int P = 998244353;

inline i64 binExp(i64 a, i64 b = P - 2, i64 p = P) {
    i64 c = 1;
    while(b) {
        if(b&1) c = c * a % p;
        a = a * a % p, b >>= 1;
    }
    return c;
}

int main() {
    i64 n, m;
    scanf("%lld%lld", &n, &m);
    i64 inv = binExp(26);
    
    i64 tot = 1, x = 1;
    for(int i = 1; i <= m; ++i) {
        if(x <= n) x *= 26;
        tot += min(i64(n), x), tot %= P;
    }
    i64 exp = 1;
    for(int i = 1; i <= m; ++i) {
        exp += (1 - binExp((1 - binExp(inv, i) + P) % P, n) + P) * binExp(26, i) % P, exp %= P;
    }
    printf("%lld %lld\n", tot, (exp + P) % P);
    return 0;
}