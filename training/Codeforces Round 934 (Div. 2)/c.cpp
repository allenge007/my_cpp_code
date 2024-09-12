#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn << 2], t[maxn << 2], n;
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), t[i - 1] = 0;
    for(int i = 0; i <= n; i ++) t[i] = 0;
    for(int i = 1; i <= n; i ++) t[a[i]] ++;
    int flag = 0;
    for(int i = 0; i <= n; i ++) {
        if(!t[i]) {
            printf("%d\n", i);
            return ;
        }
        if(flag and t[i] == 1) {
            printf("%d\n", i);
            return ;
        }
        if(t[i] == 1) flag = 1;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}