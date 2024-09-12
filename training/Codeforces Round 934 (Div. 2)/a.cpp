#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    if(k >= n - 1) printf("1\n");
    else printf("%d\n", n);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        solve();
    }
    return 0;
}