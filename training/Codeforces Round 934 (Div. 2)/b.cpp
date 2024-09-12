#include <bits/stdc++.h>

using namespace std;
const int maxn = 50005;
int a[maxn << 1], tt[maxn << 1], l[maxn << 1], r[maxn << 1];
bool flag1[maxn << 1], flag2[maxn << 1];
void solve() {
    int n, k, cnt = 0, cnt2 = 0, l1 = 0, l2 = 0;
    scanf("%d%d", &n, &k);
    k *= 2;
    for(int i = 1; i <= 2 * n; i ++)
        scanf("%d", &a[i]), tt[i] = 0, flag1[i] = flag2[i] = 0;
    for(int i = 1; i <= n; i ++) {
        tt[a[i]] ++;
    }
    for(int i = 1; i <= n; i ++) {
        if(tt[a[i]] == 2 and k >= 2 and !flag1[a[i]]) {
            cnt ++, k -= 2;
            l[++ l1] = a[i];
            l[++ l1] = a[i];
            flag1[a[i]] = 1;
        }
    }
    if(k) {
        for(int i = 1; i <= n; i ++) {
            if(tt[a[i]] == 1 and k >= 1) {
                k --, cnt2 ++;
                l[++ l1] = a[i];
                flag1[a[i]] = 1;
            }
        }
    }
    for(int i = n + 1; i <= 2 * n; i ++) {
        if(cnt and tt[a[i]] == 0 and !flag2[a[i]]) {
            r[++ l2] = a[i], r[++ l2] = a[i], flag2[a[i]] = 1;
            cnt --;
        }
        if(cnt2 and tt[a[i]] == 1 and flag1[a[i]]) {
            r[++ l2] = a[i];
            cnt2 --;
        }
    }
    for(int i = 1; i <= l1; i ++) printf("%d ", l[i]);
    printf("\n");
    for(int i = 1; i <= l2; i ++) printf("%d ", r[i]);
    printf("\n");
}
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        solve();
    }
    return 0;
}