#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e6 + 5;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot, n, m;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}

void solve() {
    n = read(), m = read();
    for(int i = 1; i <= m; i ++) {
        
    }
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}