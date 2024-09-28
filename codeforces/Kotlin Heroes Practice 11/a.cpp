#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
int T;
int main() {
    T = read();
    while(T --) {
        int x = read(), y = read();
        printf("%d %d\n", x > y ? y : x, x > y ? x : y);
    }
    return 0;
}