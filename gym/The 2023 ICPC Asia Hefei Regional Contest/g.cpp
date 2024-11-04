#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, INF = 1e9 + 7;
char str[maxn];
int sum[maxn], n, m, k;
long long f[maxn][6][2];
inline bool check(int x) {
    for(int j = 0; j <= k; j ++) f[0][j][0] = f[0][j][1] = INF;
    f[0][0][0] = f[0][0][1] = 0;
    long long tmp = INF;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; j ++) f[i][j][0] = f[i][j][1] = INF;
        if(str[i] == '0') f[i][0][0] = 0, f[i][0][1] = 1;
        else f[i][0][1] = 0;
        for(int j = 1; j <= k; ++j) {
            f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1]);
            if(i - x >= 0 && j - 1 >= 0 && str[i - x] != '1')
                f[i][j][1] = f[i - x][j - 1][0] + (sum[i] - sum[i - x]);
        }
        tmp = min({tmp, f[i][k][0], f[i][k][1]});
    }
    return tmp <= m;
}
int main() {
    scanf("%d%d%d%s", &n, &m, &k, str + 1);
    for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + ('1' - str[i]);
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r)  >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", r == 0 ? -1 : r);
    return 0;
}