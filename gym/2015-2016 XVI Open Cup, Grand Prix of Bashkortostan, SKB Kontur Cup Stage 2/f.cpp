#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
const int maxn = 305, INF = 1e9 + 7;
int a[maxn][maxn], n, vis[maxn];
pair<int, int> d1[maxn], d2[maxn], ans;
void dijkstra(int s) {
    ans = {INF, INF};
    for(int i = 1; i <= n; i ++) d1[i] = d2[i] = {INF, INF}, vis[i] = 0;
    d1[s] = {0, 0}, d2[s] = {0, 0};
    for(int i = 1; i <= n; i ++) {
        int p = 0;
        for(int j = 1; j <= n; j ++)
            if(!vis[j] && (!p || d1[j].fir < d1[p].fir)) p = j;
        if(!p) break;
        vis[p] = 1;
        for(int j = 1; j <= n; j ++) {
            if(a[p][j] > 0 && j != p) {
                auto tmp = make_pair(d1[p].fir + a[p][j], d1[p].sec);
                if(!tmp.sec) tmp.sec = j;
                if(tmp.fir < d1[j].fir) {
                    if(d1[j].sec != tmp.sec) d2[j] = d1[j], d1[j] = tmp;
                    else d1[j] = tmp;
                } else {
                    if(tmp.fir < d2[j].fir && tmp.sec != d1[j].sec) {
                        d2[j] = tmp;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(i == s) continue;
        if(d1[i].fir + d2[i].fir < ans.fir + ans.sec) ans = {d1[i].fir, d2[i].fir};
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i ++) {
        dijkstra(i);
        if(ans.fir == INF || ans.sec == INF) printf("-1\n");
        else printf("%d\n", ans.fir + ans.sec);
    }
    return 0;
}