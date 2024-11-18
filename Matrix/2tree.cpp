#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;
const double eps = 1e-5;
struct node{
    double l1, l2, r1, r2;
    int s1, s2, s3, s4, point;
}t[maxn << 4];
int n, root, cnt;
pair<double, double> a[maxn];
vector<int> dep[maxn];
bool in(double x, double y, double l1, double r1, double l2, double r2) {
    return x >= l1 && x <= l2 && y >= r1 && y <= r2;
}
int check(double l1, double r1, double l2, double r2) {
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        if(in(a[i].first, a[i].second, l1, r1, l2, r2)) num ++;
    }
    return num;
}
void build(int &p, double l1, double r1, double l2, double r2) {
    if(!p) p = ++ cnt;
    t[p].l1 = l1, t[p].r1 = r1, t[p].l2 = l2, t[p].r2 = r2;
    if(check(l1, r1, l2, r2) == 1) {
        for(int i = 1; i <=n ; i ++) {
            if(in(a[i].first, a[i].second, l1, r1, l2, r2)) t[p].point = i;
        }
        return ;
    }
    double mid1 = (l1 + l2) / 2, mid2 = (r1 + r2) / 2;
    if(check(l1 + eps, mid2 + eps, mid1, r2)) build(t[p].s1, l1 + eps, mid2 + eps, mid1, r2);
    if(check(mid1 + eps, mid2 + eps, l2, r2)) build(t[p].s2, mid1 + eps, mid2 + eps, l2, r2);
    if(check(l1 + eps, r1 + eps, mid1, mid2)) build(t[p].s3, l1 + eps, r1 + eps, mid1, mid2);
    if(check(mid1 + eps, r1 + eps, l2, mid2)) build(t[p].s4, mid1 + eps, r1 + eps, l2, mid2);
}
int maxd;
void output(int p, int d) {
    if(!p) return ;
    if(t[p].point) dep[d].push_back(t[p].point), maxd = max(maxd, d);
    output(t[p].s1, d + 1);
    output(t[p].s2, d + 1);
    output(t[p].s3, d + 1);
    output(t[p].s4, d + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    root = cnt = 1;
    build(root, -eps, -eps, 10 + eps, 10 + eps);
    output(root, 0);
    for(int i = 0; i <= maxd; i ++)
        for(auto p : dep[i]) cout << a[p].first << " " << a[p].second << "\n";
    return 0;
}