#include <bits/stdc++.h>

using namespace std;
const int maxn = 1 << 16; maxm = 105;
int n, m, f[maxn][maxm], tool[16][16];
int main() {
    int t;
    scanf("%d%d%d", &n, &m, &t);
    memset(f, -1, sizeof f);
    for(int i = 1; i <= t; i ++) {
        int x;
        scanf("%d", &x);
        f[1 << x][0] = 0;
    }
    for(int i = 1; i <= m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        tool[a][b] = c;
    }
    
    int q;
    scanf("%d", &q);
    while(q--) {
        int tmp = 0;
        scanf("%d", &t);
        for(int i = 1; i <= t; i ++) {
            int x;
            scanf("%d", &x);
            tmp |= (1 << x);
        }
        printf("%d\n", )
    }
    return 0;
}