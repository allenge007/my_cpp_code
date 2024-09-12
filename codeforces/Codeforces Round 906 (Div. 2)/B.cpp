#include <bits/stdc++.h>

using namespace std;
const int maxn = 55;
char str[maxn], ptr[maxn];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", str + 1, ptr + 1);
    bool flag = 0;
    for(int i = 1; i < m; i ++) if(ptr[i] == ptr[i + 1]) flag = 1;
    for(int i = 1; i < n; i ++) {
        if(str[i] == str[i + 1]) {
            if(flag) return printf("No\n"), void();
            if(ptr[1] == str[i] or ptr[m] == str[i + 1]) return printf("No\n"), void();
        }
    }
    printf("Yes\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}