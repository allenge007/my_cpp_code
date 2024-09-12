#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e5 + 5;
int main() {
    int n = read();
    printf("YES\n");
    for(int i = 1; i <= n; i ++) printf("%d %d\n", i, i);
    for(int i = 1; i <= n; i ++) {
        int x = read();
        if(i - x/2 >= 1) printf("%d ", i - x/2);
        else printf("%d ", i + x/2);
    }
    return 0;
}