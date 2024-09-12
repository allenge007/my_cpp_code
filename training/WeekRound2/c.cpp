#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 5;
int x[maxn], y[maxn], z[maxn], n, m, f[maxn];
bool vis[maxn];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) cin >> x[i] >> y[i] >> z[i];
    vis[0] = 1;
    for(int i = 1; i <= m; i ++) {
        if(z[i] == 0) {
            for(int j = 0; j <= n; j ++)
                if(vis[j] and j + x[i] <= n)
                    vis[j + x[i]] = 1, f[j + x[i]] = max(f[j + x[i]], f[j] + y[i]);
        }
        else{
            for(int j = n; j >= 0; j --)
                if(vis[j] and j + x[i] <= n)
                    vis[j + x[i]] = 1, f[j + x[i]] = max(f[j + x[i]], f[j] + y[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}