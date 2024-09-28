#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d%d", &n, &k);
        long long sum = (n - k + 1ll + n) * k / 2ll;
        if (sum % 2 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}