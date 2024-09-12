#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
const long long INF = 1e18;
int n, k;
long long a[maxn];
struct node{
    long long pre, nxt, num, tot;
    node(long long x = 0, long long y = 0, int z = 0, long long t = 0) : pre(x), nxt(y), num(z), tot(t) {}
    bool operator <(const node& x) const {        
        return pre - nxt < x.pre - x.nxt;
    }
};
long long calc(long long x, long long y) {
    y ++;
    if(x < y) return INF;
    long long aver = x / y, num = x % y;
    return aver * aver * (y - num) + (aver + 1) * (aver + 1) * num;
}
int main() {
    priority_queue<node> q;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        q.push(node(a[i] * a[i], calc(a[i], 1), 0, a[i]));
        ans += a[i] * a[i];
    }
    for(int i = 1; i <= k - n; i ++) {
        auto it = q.top();
        q.pop();
        // cout << it.pre << " " << it.nxt << " " << it.num << " " << it.tot << endl;
        ans -= it.pre - it.nxt;
        q.push(node(it.nxt, calc(it.tot, it.num + 2), it.num + 1, it.tot));
    }
    printf("%lld", ans);
    return 0;
}