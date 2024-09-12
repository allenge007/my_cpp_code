#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], d[maxn], n;
struct node{
    int l, r, num, id;
    node(int l = 0, int r = 0, int num = 0, int id = 0) :l(l), r(r), num(num), id(id) {}
    bool operator <(node x) const {
        return l == x.l ? r < x.r : l < x.l;
    }
}pas[maxn];
bool check(int x) {
    for(int i = 1; i <= n; i ++) pas[i] = node(max(1, i - d[i]), min(n, i + d[i]), a[i], i), b[i] = 0;
    sort(pas + 1, pas + n + 1);
    // for(int i = 1; i <= n; i ++) {
    //     cout << "passenger: " << pas[i].l << " " << pas[i].r << " " << pas[i].num << endl;
    // }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int p = 1;
    for(int i = 1; i <= n; i ++) {
        while(p <= n && pas[p].l <= i) {
            if(pas[p].num) q.push({pas[p].r, p});
            ++ p;
        }
        while(!q.empty() && q.top().first < i) {
            if(pas[q.top().second].num) return 0;
            q.pop();
        }
        while(x - b[i] > 0 && !q.empty()) {
            auto it = q.top();
            int cnt = min(pas[it.second].num, x - b[i]);
            pas[it.second].num -= cnt, b[i] += cnt;
            if(!pas[it.second].num) q.pop();
        }
        // cout << b[i] << " ";
    }
    if(!q.empty()) return 0;
    return 1;
}   
int main() {
    scanf("%d", &n);
    int l = 0, r = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), r = max(r, a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &d[i]);
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    // cout << check(0) << endl;
    printf("%d", l);
    return 0;
}