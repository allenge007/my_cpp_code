#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int n, a[maxn], p[64];
void insert(int x) {
    for(int i = 63; i >= 0; i --) {
        if((1ll << i) & x) {
            if(!p[i]) return p[i] = x, void();
            x ^= p[i];
        }
    }
}
signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        insert(a[i]);
    }
    
    return 0;
}