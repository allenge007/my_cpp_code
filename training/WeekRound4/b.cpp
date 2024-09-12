#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;
pair<int, int> a[maxn];
int tot;
string str[maxn];
bool change[35][2];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[++ tot] = make_pair(x, 1);
        if(i != n) a[++ tot] = make_pair(x, 0);
    }
    for(int i = 0; i < 33; i ++) str[0] += '0';
    int x = 0, las = 0;
    for(int i = 1; i <=m; i ++) {
        cin >> str[i];
        for(int j = 0; j < 33; j ++) {
            change[j + 1][0] = change[j + 1][1] = 0;
            if(str[i][j] != str[i - 1][j]) {
                change[j + 1][str[i][j]-'0'] = 1;
            }
        }
        while(x <= tot) {
            if(x + 1 <= tot && change[a[x + 1].first][a[x + 1].second]) x ++;
            else if(x + 2 <= tot && change[a[x + 2].first][a[x + 2].second]) x += 2;
            else if(x + 3 <= tot && change[a[x + 3].first][a[x + 3].second]) x += 3;
            else break;
        }
        if(x == 0) cout << "INITIAL\n";
        else cout << a[x].first << " " << (a[x].second == 0 ? "OFF\n" : "ON\n");
        las = x;
    }  
    return 0;
}