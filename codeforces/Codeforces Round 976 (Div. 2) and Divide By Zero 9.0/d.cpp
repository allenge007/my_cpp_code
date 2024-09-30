#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;

inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}

int n, f[maxn * 11], siz;
int r[maxn][11][11], mo[maxn][11];

inline int decode(int x, int d) {
    return x - (d - 1) * n;
}

inline int getfa(int x, int d = 0) {
    if(f[x] == x) return x;
    if(d) {
        int fx = decode(f[x], d), nx = decode(x, d);
        r[fx][d][mo[fx][d]] = max(r[fx][d][mo[fx][d]], r[nx][d][mo[nx][d]]);
    }
    return f[x] = getfa(f[x], d);
}

inline void merge(int x, int y, int d) {
    int r1 = getfa(x, d), r2 = getfa(y, d);
    if(r1 != r2) {
        int pos1 = decode(r1, d), pos2 = decode(r2, d);
        r[pos1][d][mo[x][d]] = max(r[pos1][d][mo[x][d]], r[pos2][d][mo[x][d]]);
        f[r2] = r1;
        siz --;
    }
}

inline void merge2(int x, int y) {
    int r1 = getfa(x), r2 = getfa(y);
    if(r1 != r2) {
        f[r2] = r1;
        siz --;
    }
}

void solve() {
    int m;
    n = read(), m = read();
    siz = n * 10;
    for(int i = 1; i <= n * 10; i ++) f[i] = i;
    for(int i = 1; i <= 10; i ++) {
        for(int j = 1; j <= n; j ++) {
            r[j][i][mo[j][i]] = j;
        }
    }
    for(int i = 1; i <= m; i ++) {
        int a, d, k;
        a = read(), d = read(), k = read();
        int r1 = getfa(a + (d - 1) * n, d);
        int pos = decode(r1, d);
        for(int j = r[pos][d][mo[a][d]] + d; j <= a + d * k && j <= n; j += d) {
            merge(r1, j + (d - 1) * n, d); 
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int d = 1; d <= 10; d ++)
            merge2(i, i + (d - 1) * n);
    printf("%d\n", siz);
}
int main() {
    int T;
    for(int i = 1; i <= 2e5; i ++)
        for(int d = 1; d <= 10; d ++)
            mo[i][d] = i % d;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}