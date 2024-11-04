#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if(n == 1) return printf("1\n1\n"), void();
    if(k == 1 || k == n) {
        return printf("-1\n"), void();
    }
    if(k % 2 == 0) {
        printf("3\n");
        printf("%d %d %d\n", 1, k, k + 1);
    }
    else {
        printf("3\n");
        printf("%d %d %d\n", 1, k - 1, k + 2);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}