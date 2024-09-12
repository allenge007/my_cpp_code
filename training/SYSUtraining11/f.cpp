#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 3e5 + 5;
int a[maxn], c[maxn], h[maxn], cnt, n;
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    cnt = 0;
    c[++ cnt] = 1, h[cnt] = a[1];
    for(int i = 2; i <= n; i ++) {
        if(a[i] != a[i - 1]) h[++ cnt] = a[i], c[cnt] = 1;
        else c[cnt] ++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int siz = 0, siz2 = 0;
    vector<int> cut;
    for(int i = 1; i <= cnt; i ++) {
        siz ++;
        while(siz > siz2 + 1 && q.size()) {
            auto top = q.top();
            q.pop();
            top.first --;
            siz2 ++;
            cut.push_back(top.second);
            if(top.first) q.push(top);
            else siz --;
        }
        q.push({c[i], h[i]});
    }
    while(siz > siz2 + 1 && q.size()) {
        auto top = q.top();
        q.pop();
        top.first --;
        siz2 ++;
        cut.push_back(top.second);
        if(top.first) q.push(top);
        else siz --;
    }
    // for(auto it : cut) cout << it << " ";
    // cout << endl;
    printf("%d\n", n - siz2);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}