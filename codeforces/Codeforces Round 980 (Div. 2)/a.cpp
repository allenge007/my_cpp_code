#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    if(n >= m) printf("%d\n", n);
    else {
        printf("%d\n", max(2 * n - m, 0));
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}