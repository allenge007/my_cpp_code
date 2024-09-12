#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int T, s[10], inv[10], f[maxn][10];
pair<int, int> pre[maxn][10];
char a[maxn];
void solve() {
    int n;
    scanf("%d%s", &n, a + 1);
    int ans = 0, p1 = n, p2 = 1;
    for(int i = 0; i <= 9; i ++) s[i] = i;
    for(int i = 0; i <= 9; i ++) {
        for(int j = i + 1;  j <= 9; j ++) {
            for(int k = 0; k <= 9; k ++) s[k] = k;
            for(int k = i; k <= j; k ++) s[k] = i + j - k;
            for(int k = 0; k <= 9; k ++) inv[s[k]] = k;
            f[0][s[0]] = 0;
            for(int k = 1; k <= n; k ++)
                for(int l = 0; l <= 9; l ++)
                    f[k][l] = 0;
            bool flag = 0;
            for(int k = 1; k <= n; k ++) {
                int cnt = 0;
                pair<int, int> p = {0, 0};
                for(int l = 0; l <= 9; l ++) f[k][l] = f[k - 1][l], pre[k][l] = {k - 1, l};
                for(int l = 0; l <= inv[a[k] - '0']; l ++) {
                    if(f[k - 1][l] > cnt) {
                        cnt = f[k - 1][l];
                        p = {k - 1, l};
                    }
                }
                if(cnt + 1 > f[k][inv[a[k] - '0']]) {
                    f[k][inv[a[k] - '0']] = cnt + 1;
                    pre[k][inv[a[k] - '0']] = p;
                }
                if(cnt + 1 > ans) {
                    ans = cnt + 1;
                    flag = 1;
                }
            }
            if(flag) {
                p1 = n, p2 = 1;
                int nowi = n, nowj = inv[a[n] - '0'];
                while(nowi) {
                    
                }
            }
        }
    }
    printf("%d %d %d\n", ans, p1, p2);
}
int main() {
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}