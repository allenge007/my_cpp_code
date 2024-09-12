#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
void solve() {
    int n = read(), k = read();
    vector<int> ans;
    if(k == 1) {
        ans.push_back(2), ans.push_back(3);
        for(int i = 2; (1 << i) <= n; i ++) ans.push_back(1 << i);
        printf("%d\n", ans.size());
        for(auto it : ans) printf("%d ", it);
        printf("\n");
        return ;
    }
    int lft = k - 1;
    for(int i = 0; (1 << i) <= lft; i ++) {
        lft -= (1 << i);
        ans.push_back(1 << i);
    }
    if(lft) ans.push_back(lft);
    int las = k - 1, nxt = k + 1;
    ans.push_back(k * 2);
    while(las < n) {
        ans.push_back(nxt);
        las += nxt;
        nxt = las + 1;
    }
    printf("%d\n", ans.size());
    for(auto it : ans) printf("%d ", it);
    printf("\n");
}
int main() {
    int T = read();
    while(T --) solve();
    return 0;
}