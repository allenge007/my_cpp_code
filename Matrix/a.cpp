#include <iostream>

using namespace std;
const int maxn = 10005;
int a[maxn], b[maxn], s[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
    int tot = 0, p = 1;
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i ++) {
        s[++ tot] = a[i];
        while(tot && p <= n && s[tot] == b[p]) tot --, p ++;
    }
    if(tot) printf("No\n");
    else printf("Yes\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}