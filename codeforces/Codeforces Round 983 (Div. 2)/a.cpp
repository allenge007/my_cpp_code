#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
void solve() {
    int n, on = 0, off = 0;
    scanf("%d", &n); 
    for(int i = 1; i <= 2 * n; i ++) {
        scanf("%d", &a[i]);
        if(a[i] & 1) on ++;
        else off ++;
    }
    printf("%d %d\n", on & 1, min(on, off));
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}