#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d%d", &n, &k);
        int ans = 0;
        for(int x = n; x >= 1; x --) {
            if(k <= 0) break;
            if(x == n) {
                k -= n, ans ++;
            }
            else {
                k -= x, ans ++;
                if(k > 0) k -= x, ans ++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}