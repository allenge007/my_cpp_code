#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int n, m, a[maxn], siz[maxn], f[maxn];
vector<int> tower[maxn];
int getfa(int x) {
    if(f[x] == x) return x;
    return f[x] = getfa(f[x]);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        tower[a[i]].push_back(i);
        siz[a[i]] ++;
    }
    for(int i = 1; i <= m; i ++) f[i] = i;
    int ans = n - 1;
    for(int i = 1; i < n; i ++) {
        if(a[i] == a[i + 1]) ans --;
    }
    printf("%d\n", ans);
    for(int i = 1; i < m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int r1 = getfa(x), r2 = getfa(y);
        if(r1 == r2) {
            printf("%d\n", ans);
            continue;
        }
        if(tower[r1].size() < tower[r2].size()) swap(r1, r2);
        int cnt = 0;
        for(auto it : tower[r2]) {
            if(it > 1 && getfa(a[it - 1]) == r1) ans --;
            if(it < n && getfa(a[it + 1]) == r1) ans --;
            tower[r1].push_back(it);
        }
        f[r2] = r1;
        printf("%d\n", ans);
    }
    return 0;
}