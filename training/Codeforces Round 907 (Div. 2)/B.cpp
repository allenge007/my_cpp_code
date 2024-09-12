#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], x[maxn];
void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    int las = 31;
    for(int i = 1; i <= q; i ++) {
        int x;
        scanf("%d", &x);
        // cout<<x<<endl;
        if(x < las) {
            las = x;
            // cout<<x<<endl;
            for(int j = 1; j <= n; j ++) {
                if(a[j] % (1 << x) == 0) {
                    a[j] += (1 << (x - 1));
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++)
        printf("%d ", a[i]);
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}