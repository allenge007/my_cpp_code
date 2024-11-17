#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
int n[maxn], k[maxn];
inline long long qpow(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i ++) scanf("%d", &n[i]);
    for(int i = 0; i < t; i ++) scanf("%d", &k[i]);
    for(int i = 0; i < t; i ++) {
        if(k[i] == 0 || k[i] == n[i]) printf("1\n");
        else {
            printf("%lld\n", qpow(2, k[i]));
        }
    }
    return 0;
}
/*
1
1 1
1 2 1
1 2 4 1
1 2 4 8 1
1 2 3 8 16 1

*/