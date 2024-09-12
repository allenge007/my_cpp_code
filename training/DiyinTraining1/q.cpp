#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 2e5 + 5;
int pos[maxn], tar[maxn], n;
int main() {
    n = read();
    printf("YES\n");
    for(int i = 1; i <= n; i ++) {
        int x = read();
        // cout << i << " " << x << endl;
        if(!x) pos[i] = 1, tar[i] = i;
        else if(x <= i - 1) pos[i] = pos[i - x], tar[i] = i - x;
        else pos[i] = x - i + 2, tar[i] = 1;
        printf("%d %d\n", i, pos[i]);
    }
    for(int i = 1; i <= n; i ++) printf("%d ", tar[i]);
    return 0;
}