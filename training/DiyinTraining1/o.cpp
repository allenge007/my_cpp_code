#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 2e5 + 5;
char str[maxn];
void solve() {
    int n = read();
    scanf("%s", str + 1);
    int dr = 1, l = n + 1, r = 0, pos = 0;
    for(int i = 1; i <= n; i ++) {
        if(str[i] == str[i - 1]) {
            dr = -dr;
        }
        else pos += dr;
        l = min(l, pos), r = max(r, pos);
    }
    printf("%d\n", r - l + 1);
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}