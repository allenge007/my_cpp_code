#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char d[maxn][maxn], f[maxn][maxn];
int n, m, h;
bool vis[maxn][maxn], vis2[maxn][maxn];
vector< tuple<int, int, int> > maxans, minans;
int main() {
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= n; i ++)
        scanf("%s", d[i] + 1);
    for(int i = 1; i <= n; i ++)
        scanf("%s", f[i] + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(d[i][j] == '1') {
                int sum = 0;
                for(int k = 1; k <= h; k ++)
                    if(f[i][k] == '1') sum ++, maxans.push_back(make_tuple(i, j, k)), vis2[i][k] = 1;
                if(sum == 0) return printf("-1\n"), 0;
            }
        }
    }
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= h; j ++) if(f[i][j] == '1' and !vis2[i][j]) return printf("-1\n"), 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(d[i][j] == '1') {
                int sum = 0;
                for(int k = 1; k <= h; k ++) {
                    if(f[i][k] == '1' and !vis[i][k]) {
                        vis[i][k] = 1, sum ++, minans.push_back(make_tuple(i, j, k));
                        break;
                    }
                }
                if(sum == 0) {
                    for(int k = 1; k <= h; k ++) {
                        if(f[i][k] == '1') {
                            sum ++;
                            minans.push_back(make_tuple(i, j, k));
                            break;
                        }
                    }
                    if(sum == 0) return printf("-1\n"), 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= h; j ++) {
            if(f[i][j] == '1' and !vis[i][j]) {
                int sum = 0;
                for(int k = 1; k <= m; k ++) {
                    if(d[i][k] == '1') {
                        sum ++;
                        minans.push_back(make_tuple(i, j, k));
                        break;
                    }
                }
                if(!sum) return printf("-1\n"), 0;
            }
        }
    sort(maxans.begin(), maxans.end());
    printf("%d\n", maxans.size());
    for(auto it = maxans.begin(); it != maxans.end(); ++ it) {
        printf("%d %d %d\n", get<0>(*it) - 1, get<1>(*it) - 1, get<2>(*it) - 1);
    }
    sort(minans.begin(), minans.end());
    printf("%d\n", minans.size());
    for(auto it = minans.begin(); it != minans.end(); ++ it) {
        printf("%d %d %d\n", get<0>(*it) - 1, get<1>(*it) - 1, get<2>(*it) - 1);
    }
    return 0;
}