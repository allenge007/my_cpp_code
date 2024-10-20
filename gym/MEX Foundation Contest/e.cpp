#include <bits/stdc++.h>

using namespace std;
const int maxn = 20;
int a[maxn][maxn], n, m, s;
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] ++, a[y][x] ++;
    }
    
    return 0;
}