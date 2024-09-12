#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 0 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 2e5 + 5;
int c[maxn];
void add(int x, int n) {
    for(; x <= n; x += x & -x)
        c[x] ++;
}
int ask(int x) {
    int cnt = 0;
    for(; x; x -= x & -x)
        cnt += c[x];
    return cnt;
}
void solve() {
    int n = read();
    int *p = new int[n], *ans = new int[n];
    for(int i = 1; i <= n; i ++) c[i] = 0;
    for(int i = 0; i < n; i ++) {
        p[i] = read();
    }
    if(p[0] == 1) ans[0] = 0;
    else ans[0] = -p[0];
    for(int i = 1; i < n; i ++) {
        
    }
    delete []p;
    delete []ans;
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}