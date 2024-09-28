#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 55;
int n, k, a[maxn];
int main() {
    int T = read();
    while(T --) {
        n = read(), k = read();
        for(int i = 1; i <= n; i ++) a[i] = read();
        int coin = 0, ans = 0;
        for(int i = 1; i <= n; i ++) {
            if(a[i] >= k) coin += a[i];
            else if(a[i] == 0 && coin) coin --, ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}