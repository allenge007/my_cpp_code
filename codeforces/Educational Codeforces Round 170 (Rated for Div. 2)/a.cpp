#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e5 + 5;
char str[maxn], ptr[maxn];
void solve() {
    scanf("%s%s", str, ptr);
    int n = strlen(str), m = strlen(ptr);
    int p = 0;
    for(int i = 0; i < min(n, m); i ++) {
        if(str[i] == ptr[i]) p ++;
        else break;
    }
    if(p) printf("%d\n", n + m - p + 1);
    else printf("%d\n", n + m);
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}