#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int n, m, K, A[7], a[maxn], b[maxn], d[maxn], pi[maxn], pj[maxn], op[maxn], v[maxn];
long long ans;
void dfs(int x) {
    if(x == n + 1) {
        long long cnt = 0;
        for(int i = 1; i <= m; i ++) {
            if(op[i] == 0) {
                if(a[i] * A[pi[i]] + b[i] * A[pj[i]] <= d[i]) cnt += v[i];
            }
            else {
                if(a[i] * A[pi[i]] + b[i] * A[pj[i]] >= d[i]) cnt += v[i];
            }
        }
        ans = max(ans, cnt);
        return ;
    }
    for(int i = 0; i <= K; i ++) {
        A[x] = i;
        dfs(x + 1);
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d%d%d%d%d%d", &pi[i], &pj[i], &op[i], &a[i], &b[i], &d[i], &v[i]);
    }
    dfs(1);
    printf("%lld", ans);
    return 0;
}