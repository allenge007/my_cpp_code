#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n, f[maxn], L[maxn], R[maxn], maxi[maxn];
struct node{
    int id, l, r;
    node(int id = 0, int l = 0, int r = 0) : id(id), l(l), r(r) {};
    bool operator <(const node& x) const {
        return id > x.id;
    }
}seg[maxn];
inline int getfa(int x) {
    if(f[x] == x) return x;
    return f[x] = getfa(f[x]);
}
void merge(int x, int y) {
    int r1 = getfa(x), r2 = getfa(y);
    if(r1 != r2) {
        maxi[r1] = max(maxi[r1], maxi[r2]);
        L[r1] = min(L[r1], L[r2]), R[r1] = max(R[r1], R[r2]);
        f[r2] = r1;
    }
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int cnt = 0;
    seg[++ cnt] = node(a[1], 1, 1);
    for(int i = 2; i <= n; i ++) {
        if(a[i] == a[i - 1]) seg[cnt].r ++;
        else {
            seg[++ cnt] = node(a[i], i, i);
        }
    }
    priority_queue<node> q;
    for(int i = 1; i <= cnt; i ++) {
        q.push(seg[i]);
    }
    for(int i = 1; i <= n; i ++) f[i] = i, maxi[i] = a[i], L[i] = R[i] = i;
    for(int i = 2; i <= n; i ++) {
        if(a[i] == a[i - 1]) merge(i, i - 1);
    }
    long long ans = 0;
    while(!q.empty()) {
        auto u = q.top();
        q.pop();
        int x = L[getfa(u.l)], y = R[getfa(u.r)];
        if(u.l != x || u.r != y) continue;
        if(x == 1 && y == n) continue;
        int lsum = 0, rsum = 0;
        if(x == 1) {
            lsum = maxi[getfa(y + 1)];
            if(lsum > u.id) {
                ans += u.r - u.l + 1;
                merge(y, y + 1);
                q.push(node(lsum, L[getfa(x)], R[getfa(x)]));
            }
            // cout << u.id << " " << u.l << " " << u.r << " " << lsum << " " << rsum <<endl;
        }
        else if(y == n) {
            rsum = maxi[getfa(x - 1)];
            if(rsum > u.id) {
                ans += u.r - u.l + 1;
                merge(x, x - 1);
                q.push(node(rsum, L[getfa(x)], R[getfa(x)]));
            }
            // cout << u.id << " " << u.l << " " << u.r << " " << lsum << " " << rsum <<endl;
        }
        else {
            lsum = maxi[getfa(y + 1)];
            rsum = maxi[getfa(x - 1)];
            // cout << u.id << " " << u.l << " " << u.r << " " << lsum << " " << rsum <<endl;
            if(rsum < lsum) {
                if(rsum > u.id) {
                    ans += u.r - u.l + 1;
                    merge(x, x - 1);
                    q.push(node(rsum, L[getfa(x)], R[getfa(x)]));
                }
            }
            else if(rsum > lsum) {
                if(lsum > u.id) {
                    ans += u.r - u.l + 1;
                    merge(y, y + 1);
                    q.push(node(lsum, L[getfa(x)], R[getfa(x)]));
                }
            }
            else if(rsum == lsum) {
                ans += u.r - u.l + 1;
                merge(x, x -  1);
                merge(y, y + 1);
                q.push(node(lsum, L[getfa(x)], R[getfa(y)]));
            }
        }
    }
    printf("%lld\n", ans);
};
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}