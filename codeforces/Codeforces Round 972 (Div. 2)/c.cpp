#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
char str[maxn][maxn];
int f[maxn][5], num[maxn][5], Next[maxn][5];
bool vis[maxn][5];
inline int getID(char ch) {
    if(ch == 'n') return 0;
    if(ch == 'a') return 1;
    if(ch == 'r') return 2;
    if(ch == 'e') return 3;
    if(ch == 'k') return 4;
    return -1;
}
inline char getCh(int x) {
    if(x == 0) return 'n';
    if(x == 1) return 'a';
    if(x == 2) return 'r';
    if(x == 3) return 'e';
    return 'k';
}
inline char nxt(char x) {
    return getCh((getID(x) + 1) % 5);
}
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%s", str[i] + 1);
    for(int i = 0; i <= n; i ++)
        for(int k = 0; k < 5; k ++)
            num[i][k] = Next[i][k] =  0;
    for(int i = 1; i <= n; i ++) {
        for(int k = 0; k < 5; k ++) {
            char tmp = getCh(k);
            int cntn = 0, cntc = 0;
            for(int j = 1; j <= m; j ++) {
                if(str[i][j] == tmp) {
                    tmp = nxt(tmp);
                    if(tmp == 'n') cntn += 5;
                }
                else if(getID(str[i][j]) >= 0) cntc ++;
            }
            num[i][k] = cntn - cntc;
            Next[i][k] = getID(tmp);
        }
    }
    for(int i = 0; i <= n; i ++)
        for(int k = 0; k < 5; k ++)
            vis[i][k] = 0, f[i][k] = 0;
    vis[0][0] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int k = 0; k < 5; k ++) {
            if(!vis[i - 1][k]) continue;
            if(!vis[i][k] || f[i][k] < f[i - 1][k]) {
                f[i][k] = f[i - 1][k];
                vis[i][k] = 1;
            }
            if(!vis[i][Next[i][k]] || f[i][Next[i][k]] < f[i - 1][k] + num[i][k]) {
                f[i][Next[i][k]] = f[i - 1][k] + num[i][k];
                if(Next[i][k] != 0) {
                    ans = max(ans, f[i][Next[i][k]] - Next[i][k]);
                }
                else ans = max(ans, f[i][Next[i][k]]);
                vis[i][Next[i][k]] = 1;
            }
        }
    }
    printf("%d\n", ans);
;}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}