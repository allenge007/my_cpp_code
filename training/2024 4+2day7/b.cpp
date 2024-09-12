#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
char str[maxn];
struct node{
    int l, r, mini, maxi, tag;
}t[maxn << 2];
void update(int p) {
    t[p].mini = min(t[p << 1].mini, t[p << 1 | 1].mini);
    t[p].maxi = max(t[p << 1].maxi, t[p << 1 | 1].maxi);
}
void spread(int p) {
    if(t[p].tag) {
        int mini1 = t[p << 1].mini, maxi1 = t[p << 1].maxi;
        t[p << 1].mini = 1 - maxi1, t[p << 1].maxi = 1 - mini1;
        mini1 = t[p << 1 | 1].mini, maxi1 = t[p << 1 | 1].maxi;
        t[p << 1 | 1].mini = 1 - maxi1, t[p << 1 | 1].maxi = 1 - mini1;
        t[p << 1].tag ^= 1, t[p << 1 | 1].tag ^= 1;
        t[p].tag ^= 1;
        t[p].mini = min(t[p << 1].mini, t[p << 1 | 1].mini);
        t[p].maxi = max(t[p << 1].maxi, t[p << 1 | 1].maxi);
    }
}
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r, t[p].tag = 0;
    if(l == r) {
        t[p].maxi = t[p].mini = str[l] - '0';
        t[p].tag = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
int askl0(int p, int l, int r) {
    if(l == r) {
        if(t[p].mini != 0) return -1;
        else return l;
    }
    spread(p);
    int mid = (l + r) >> 1, x = 0;
    if(t[p << 1].mini == 0) x = askl0(p << 1, l, mid);
    else x = askl0(p << 1 | 1, mid + 1, r);
    update(p);
    return x;
}
int askr0(int p, int l, int r) {
    if(l == r) {
        if(t[p].mini != 0) return -1;
        else return l;
    }
    spread(p);
    int mid = (l + r) >> 1, x = 0;
    if(t[p << 1 | 1].mini == 0) x = askr0(p << 1 | 1, mid + 1, r);
    else x = askr0(p << 1, l, mid);
    update(p);
    return x;
}
int askl1(int p, int l, int r) {
    if(l == r) {
        if(t[p].maxi != 1) return -1;
        else return l;
    }
    spread(p);
    int mid = (l + r) >> 1, x = 0;
    if(t[p << 1].maxi == 1) x = askl1(p << 1, l, mid);
    else x = askl1(p << 1 | 1, mid + 1, r);
    update(p);
    return x;
}
int askr1(int p, int l, int r) {
    if(l == r) {
        if(t[p].maxi != 1) return -1;
        else return l;
    }
    spread(p);
    int mid = (l + r) >> 1, x = 0;
    if(t[p << 1 | 1].maxi == 1) x = askr1(p << 1 | 1, mid + 1, r);
    else x = askr1(p << 1, l, mid);
    update(p);
    return x;
}
void change(int p, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) {
        t[p].tag ^= 1;
        int mini1 = t[p].mini, maxi1 = t[p].maxi;
        t[p].mini = 1 - maxi1, t[p].maxi = 1 - mini1;
        return ;
    }
    spread(p);
    int mid = (l + r) >> 1;
    if(ql <= mid) change(p << 1, l, mid, ql, qr);
    if(qr > mid) change(p << 1 | 1, mid + 1, r, ql, qr);
    update(p);
}
void solve() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    scanf("%s", str + 1);
    build(1, 1, N);
    while(Q --) {
        int l, r;
        scanf("%d%d", &l, &r);
        change(1, 1, N, l, r);
        int min0 = askl0(1, 1, N), max0 = askr0(1, 1, N), min1 = askl1(1, 1, N), max1 = askr1(1, 1, N);
        int ans = 0;
        if(min0 < max0 && min0 > -1 && max0 > -1) ans = max(ans, max0 - min0);// cout << "zero: " <<  min0 << " " << max0 << endl;
        if(min1 < max1 && min1 > -1 && max1 > -1) ans = max(ans, max1 - min1);// cout << "one: " << min1 << " " << max1 << endl;
        printf("%d\n", ans);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}