#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e3 + 5;
void solve() {
    int n = read(), k = read();
    if(k == 1) {
        for(int i = 1; i <= n; i ++)
            printf("%d ", i);
        printf("\n");
        return ;
    }
    else if(n != k) {
        return printf("-1\n"), void();
    }
    for(int i = 1; i <= n; i ++)
        printf("1 ");
    printf("\n");
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}