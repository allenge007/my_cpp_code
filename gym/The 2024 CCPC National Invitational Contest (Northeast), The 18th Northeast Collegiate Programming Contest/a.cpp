#include <bits/stdc++.h>

using namespace std;
int x, k, las;
long long ans;
map<int, bool> S;
int main() {
    scanf("%d%d", &x, &k);
    while(x > 1 && k >= 0) {
        int y = sqrt(x);
        if((long long)x * x != las) ans += k + 1;
        else ans ++;
        k --, las = x, x = y;
    }
    if(k > -1) ans ++;
    printf("%lld", ans);
    return 0;
}