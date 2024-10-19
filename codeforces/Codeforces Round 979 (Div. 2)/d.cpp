#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int n, q, p[maxn];
char str[maxn];
void solve() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    scanf("%s", str + 1);
    int maxi = 0;
    set<int> S;
    for(int i = 1; i <= n; i ++) {
        maxi = max(maxi, p[i]);
        if(maxi == i) S.insert(i);   
    }
    int cnt = 0;
    for(int i = 1; i < n; i ++) {
        if(str[i] == 'L' && str[i + 1] == 'R') {
            if(S.find(i) == S.end()) cnt ++;
            // cout << i << " " << cnt <<  "fick\n";
        }
    }
    for(int i = 1; i <= q; i ++) {
        int x;
        scanf("%d", &x);
        if(str[x] == 'L') str[x] = 'R';
        else str[x] = 'L';
        if(str[x] == 'L' && str[x + 1] == 'R') {
            if(S.find(x) == S.end()) {
                cnt ++;
            }
        }
        if(str[x - 1] == 'L' && str[x] == 'R') {
            if(S.find(x - 1) == S.end()) {
                cnt ++;
            }
        }
        if(str[x - 1] == 'L' && str[x] == 'L') {
            if(S.find(x - 1) == S.end()) {
                cnt --;
            }
        }
        if(str[x] == 'R' && str[x + 1] == 'R') {
            if(S.find(x) == S.end()) {
                cnt --;
            }
        }
        // cout <<"*****\n" <<cnt << "******"<< endl;
        if(cnt == 0) printf("YES\n");
        else printf("NO\n");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}