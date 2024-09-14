#include <bits/stdc++.h>

using namespace std;
const int maxn = 305;
int a[maxn], b[maxn][maxn], sg[305][maxn][maxn], sum[305][maxn][maxn];
void solve() {
    int l, n, m;
    scanf("%d%d%d", &l, &n, &m);
    for(int i = 1; i <= l; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            scanf("%d", &b[i][j]);
    for(int k = 1; k <= l + 1; k ++)
    for(int i = 1; i <= n + 1; i ++)
        for(int j = 1; j <= m + 1; j ++)
            sg[k][i][j] = sum[k][i][j] = 0;
    for(int k = l; k >= 1; k --) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(i == n || j == m) {
                    if(b[i][j] == a[k]) sg[k][i][j] = sum[k][i][j] = 1;
                    else sg[k][i][j] = sum[k][i][j] = 0;
                }
                else if(b[i][j] == a[k] && !sum[k + 1][i + 1][j + 1]) sg[k][i][j] = 1, sum[k][i][j] = 1;
                else sg[k][i][j] = 0, sum[k][i][j] = 0;
            }
        }
        for(int i = n; i >= 1; i --)
            for(int j = m; j >= 1; j --)
                sum[k][i][j] += sum[k][i + 1][j] + sum[k][i][j + 1] - sum[k][i + 1][j + 1];
    }
    bool flag = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(a[1] == b[i][j] && sg[1][i][j]) flag = 1;
    if(flag) printf("T\n");
    else printf("N\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}