#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e6 + 5;
int a[maxn << 1], prime[maxn / 10], phi[maxn], cnt, f[maxn << 1], lth[maxn];
bool vis[maxn];
vector<int> fac[maxn], P[maxn];
int getfa(int x) {
    if(f[x] == x) return x;
    return f[x] = getfa(f[x]);
}
void merge(int x, int y) {
    int r1 = getfa(x), r2 = getfa(y);
    if(r1 == r2) return ;
    f[r2] = r1;
}
void solve() {
    long long ans = 0;
    int n = read(), k = read();
    for(int i = 1; i <= n; i ++) {
        a[i + n - 1] = read();
        if(a[i + n - 1] == 1) ans += n;
    }
    for(int i = 1; i < n; i ++) a[i] = a[i + n];
    vector<int> S;
    for(int i = 1; i < 2 * n; i ++) {
        // cout << lth[a[i]] << " " << a[i] << endl;
        // cout << "a[" << i <<  "] = {";
        for(int j = 0; j < lth[a[i]]; j ++) {
            // if(j <= 1) break;
            S.push_back(fac[a[i]][j]);
            P[fac[a[i]][j]].push_back(i);
            // cout << fac[a[i]][j] << ((j == lth[a[i]] - 1) ? "}\n" : ", ");
        }
    }
    sort(S.begin(), S.end());
    int l = unique(S.begin(), S.end()) - S.begin();
    for(int i = 1; i < 2 * n; i ++) f[i] = i;
    for(int i = 0; i < l; i ++) {
        int lenth = P[S[i]].size();
        // cout << S[i] << ": \n";
        for(int j = 0; j < lenth - 1; j ++) {
            if(P[S[i]][j + 1] - P[S[i]][j] <= k) merge(P[S[i]][j + 1], P[S[i]][j]);
        }
        P[S[i]].clear();
    }
    for(int i = 1; i < 2 * n; i ++) {
        if(a[i] > 1) {
            // cout << i << " " << getfa(i) << endl;
            if(getfa(i) == i) ans ++;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    for(int i = 2; i <= 1000000; i ++) {
        if(!vis[i]) prime[++ cnt] = i, phi[i] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= 1000000; j ++) {
            vis[i * prime[j]] = 1;
            phi[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
    for(int i = 1; i <= 1000000; i ++) {
        int x = i;
        // cout << x << " " << phi[x] << endl;
        while(x > 1) {
            fac[i].push_back(phi[x]);
            x /= phi[x];
        }
        // cout << i << " ";
        sort(fac[i].begin(), fac[i].end());
        lth[i] = unique(fac[i].begin(), fac[i].end()) - fac[i].begin();
    }
    int T = read();
    while(T --) solve();
    return 0;
}