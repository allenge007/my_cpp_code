#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
char str[maxn];
void solve() {
    int n, cnt0 = 0, cnt1 = 0;
    scanf("%d", &n);
    scanf("%s", str + 1);
    if(str[1] == '1' || str[n] == '1') {
        return printf("YES\n"), void();
    }
    for(int i = 2; i <= n; i ++) {
        if(str[i] == '1' && str[i] == str[i - 1]) {
            return printf("YES\n"), void();
        }
    }
    printf("NO\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}