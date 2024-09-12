#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 1e5 + 5;
set<int> p;
multiset<int> g;
void add(int x) {
    // cout << x <<  " ";
    auto it = p.insert(x).first;
    if(next(it) != p.end()) g.insert(*next(it) - x);
    if(it != p.begin()) {
        g.insert(x - *prev(it));
        if(next(it) != p.end()) g.erase(g.find(*next(it) - *prev(it)));
        // cout << "fuck dick" << *prev(g.rbegin()) << endl;
    }
}
void erase(int x) {
    auto it = p.find(x);
    if(next(it) != p.end()) g.erase(g.find(*next(it) - x));
    if(it != p.begin()) {
        g.erase(g.find(x - *prev(it)));
        if(next(it) != p.end()) g.insert(*next(it) - *prev(it));
    }
    p.erase(it);
}
void solve() {
    int n = read(), q = read();
    for(int i = 1; i <= n; i ++) add(read());
    if(p.size() > 2) printf("%lld\n", (long long)*p.rbegin() - *p.begin() * 1ll - *g.rbegin() * 1ll);
    else printf("0\n");
    while(q --) {
        int opt = read(), x = read();
        if(!opt) erase(x);
        else add(x);
        // cout << "fuck" << *g.rbegin() << endl;
        if(p.size() > 2) printf("%lld\n", (long long)*p.rbegin() - *p.begin() * 1ll - *g.rbegin() * 1ll);
        else printf("0\n");
    }
}
int main() {
    solve();
    return 0;
}