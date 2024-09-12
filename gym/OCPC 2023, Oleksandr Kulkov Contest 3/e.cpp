#include <bits/stdc++.h>

using namespace std;
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
void solve() {
    int x, y;
    scanf("%d%d", &x, &y);
    if((y - x + 1) % 2 == 0) {
        for(int i = x; i <= y; i += 2) printf("%d %d ", i + 1, i);
        printf("\n");
        return ;
    }
    if(x % 2 == 0) return printf("-1\n"), void();
    if(x == y && x != 1) return printf("-1\n"), void();
    if(x == 1 && y == 1) return printf("1\n"), void();
    printf("%d %d %d ", x + 1, x + 2, x);
    for(int i = x + 3; i <= y; i += 2) printf("%d %d ", i + 1, i);
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}