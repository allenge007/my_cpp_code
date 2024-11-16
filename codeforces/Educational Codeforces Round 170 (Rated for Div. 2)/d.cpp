#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6 + 5, maxm = 5005;
int n, m, r[maxn], f[maxm << 1][maxm];
vector<int> S[maxm << 1], I[maxm << 1];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &r[i]);
    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(r[i] == 0) cnt ++;
        if(abs(r[i]) > cnt) continue;
        if(cnt >= 2 * m) {
            if(r[i] != 0) ans ++;
        } else {
            if(r[i] > 0) S[cnt].push_back(r[i]);
            if(r[i] < 0) I[cnt].push_back(-r[i]);
        }
    }
    for(int i = 1; i <= 2 * m; i ++) sort(S[i].begin(), S[i].end()), sort(I[i].begin(), I[i].end());
    int ans2 = 0;
    for(int i = 0; i < 2 * m; i ++) {
        for(int j = 0; j <= i; j ++) {
            int i1 = upper_bound(I[i + 1].begin(), I[i + 1].end(), i - j) - I[i + 1].begin();
            int i2 = upper_bound(I[i + 1].begin(), I[i + 1].end(), i - j + 1) - I[i + 1].begin();
            int s1 = upper_bound(S[i + 1].begin(), S[i + 1].end(), j) - S[i + 1].begin();
            int s2 = upper_bound(S[i + 1].begin(), S[i + 1].end(), j + 1) - S[i + 1].begin();
            f[i + 1][j] = max(f[i + 1][j], f[i][j] + i2 + s1);
            f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + i1 + s2);
        }
    }
    for(int j = 0; j <= m; j ++) ans2 = max(ans2, f[2 * m][j]);
    printf("%d\n", ans + ans2);
    return 0;
}