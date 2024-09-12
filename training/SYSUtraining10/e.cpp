#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e6 + 6;
int T, a[maxn], b[maxn];
void solve() {
    int n = read();
    long long sum = 0;
    for(int i = 1; i <= n; i ++) a[i] = read(), b[i] = read() - a[i], sum += b[i];
    long long cnt = 0;
    bool flag = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i]) {
            cnt += a[i];
            continue;
        }
        long long tmp = b[i];
        while(a[i + 1] == 0 && i + 1 <= n) tmp += b[++ i];
        if(tmp * 2 > cnt + sum) {
            flag = 1;
            break;
        }
    }
    printf(flag ? "NO\n" : "YES\n");
}
int main() {
    T = read();
    while(T --) solve();
    return 0;
}