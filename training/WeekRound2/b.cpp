#include <bits/stdc++.h>

using namespace std;
const int maxn = 505, inf = 1e9 + 7;
int f[maxn][maxn], a[maxn][maxn], n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> a[i][j];
    if(a[1][1] == 1) f[1][1] = -1;
    if(a[1][1] == 2) f[1][1] = 1;
    for(int i = 0; i <= max(n, m); i ++)
        f[0][i] = f[i][0] = - inf;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            if(i == j and i == 1) continue;
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i][j] == 1) f[i][j] -= 1;
            else if(a[i][j] == 2) f[i][j] += 1;
        }
    cout << f[n][m];
    return 0;
}