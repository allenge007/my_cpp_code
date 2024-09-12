#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, INF = 1e9 + 7;
int mini[maxn << 2];
pair<int, int> ans[maxn];
int n, a[maxn], b[maxn];
void update(int p) {
	mini[p] = min(mini[p << 1], mini[p << 1 | 1]);
}
void build(int p, int l, int r) {
	if(l == r) return mini[p] = b[l], void();
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	update(p);
}
int check(int p, int l, int r, int ql, int qr) {
	if(ql <= l and qr >= r) return mini[p];
    int mid = (l + r) >> 1, mm = n + 1;
    if(ql <= mid) mm = min (mm, check(p << 1, l, mid, ql, qr));
    if(qr > mid) mm = min (mm, check(p << 1 | 1, mid + 1, r, ql, qr));
    return mm;
}
void clear(int p, int l, int r, int x) {
    if(l == r) return mini[p] = n + 1, void ();
    int mid = (l + r) >> 1;
    // cout<<"\n#"<<p<<" "<<l<<" "<<r;
    if(x <= mid) clear(p << 1, l, mid, x);
    else clear(p << 1 | 1, mid + 1, r, x);
    update(p);
}
int main(){
	int tail = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[a[i]] = i;
    b[n + 1] = a[n + 1] = n + 1;
	build(1, 1, n + 1);
    for(int i = 1; i <= n; i ++) {
        int nx = check(1, 1, n + 1, a[i], a[i]);
        // cout<<i<<" "<<nx<<"###\n";
        if(nx == n + 1) continue;
        int x = i, y = check(1, 1, n + 1, a[i] + 1, n + 1);
        ans[++ tail] = make_pair(a[x], a[y]);
        clear(1, 1, n + 1, a[y]), clear(1, 1, n + 1, a[x]);
        // cou<<check(1, 1, n + 1, a[y], a[y])<<" "<<check(1, 1, n + 1, x, x])<<endl;
    }
	printf("%d\n", tail);
	for(int i = 1; i <= tail; i ++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}