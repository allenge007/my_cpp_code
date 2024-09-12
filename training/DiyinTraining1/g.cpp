#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
long long ans;
int a[maxn], n;
struct node{
    long long val, w, num;
    int id;
    node(long long val, long long w, long long num, int id) : val(val), w(w), num(num), id(id) {}
    bool operator <(const node x) const {
        return val > x.val;
    }
};
long long D(long long x) {return x * x;}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    priority_queue<node> q, p;
    for(int i = 1; i <= n; i ++) {
        q.push(node(a[i], a[i], 1, i));
    }
    p.push(q.top());
    q.pop();
    while(!q.empty()) {
        auto u = q.top(), v = p.top();
        ans += v.val + u.val;
        // cout << u.id << " connect " << v.id << " " << u.val << " " << u.num << " " << v.val << " " << v.num << endl;
        q.pop(), p.pop();
        p.push(node((D(v.num + 1) - D(v.num)) * v.w, v.w, v.num + 1, v.id));
        p.push(node((D(u.num + 1) - D(u.num)) * u.w, u.w, u.num + 1, u.id));
        
    }
    printf("%lld", ans);
    return 0;
}