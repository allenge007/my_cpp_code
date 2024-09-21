#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) {
        int n;
        cin >> n;
        long long k = floor(sqrt(8ll * n)) / 2;
        long long x, y;
        for(long long i = k - 10; i <= k + 10; i ++) {
            x = 2ll * n - 1ll * i * i - i, y = 2ll * (i + 1);
            if(x < y && x >= 0 && y >= 0) {
                x += 2ll * i * i + 2ll * i;
                printf("%lld %lld\n", x / __gcd(x, y), y/__gcd(x, y));
                break;
            }  
        }
    }
    return 0;
}