#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], ex[maxn];
struct node{
    int a, b, p, tag, to;
    node(int a = 0, int b = 0, int p = 0, int tag = 0, int to = 0) : a(a), b(b), p(p), tag(tag), to(to) {}
    node(const node& x) {
        a = x.a, b = x.b, p = x.p, tag = x.tag, to = x.to;
    }
};
bool cmp(node x, node y) {
    if(x.b == y.b) return x.a < y.a;
    return x.b < y.b;
}
bool cmp2(node x, node y) {
    if(x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}
void solve() {
    int n;
    vector<node> A, B, Now;
    vector<pair<int, int>> ans;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i ++) {
        Now.push_back(node(a[i], b[i], i));
        if(a[i] <= b[i]) A.push_back(node(a[i], b[i], i));
        else B.push_back(node(a[i], b[i], i));
    }
    sort(B.begin(), B.end(), cmp);
    sort(A.begin(), A.end(), cmp2);
    if(B.size() % 2 == 1 && B.size() > 1) {
        int cnt = 2 * n + 1, p = 0;
        for(int i = B.size() - 1; i >= 0; i --) {
            if(B[i].a < cnt) {
                cnt = B[i].a, p = i;
            }
            if(B[i].b != B[i - 1].b) break;
        }
        int bb = B.size();
        for(int i = 0; i < bb; i ++) if(i != p) B[i].tag = 1, Now[B[i].p - 1].tag = 1;
    }
    else {
        for(auto it : B) it.tag = 1;
    }
    vector<node> C;
    int i = 0, j = 0, na = A.size(), nb = B.size();
    while(i < na && j < nb) {
        node cp1(A[i]), cp2(B[j]);
        if(cp2.tag) swap(cp2.a, cp2.b);
        // cout << cp1.a << " " << cp1.b << " : " << cp2.a << " " << cp2.b << endl; 
        if(cp1.a == cp2.a) {
            if(cp1.b <= cp2.b) C.push_back(A[i ++]);
            else C.push_back(B[j ++]);
        }
        else if(cp1.a < cp2.a) C.push_back(A[i ++]);
        else C.push_back(B[j ++]);
    }
    // cout << i << " " << j << endl;
    while(i < na) C.push_back(A[i ++]);
    while(j < nb) C.push_back(B[j ++]);
    for(int i = 0; i < n; i ++) {
        Now[C[i].p - 1].to = i + 1;
        ex[i + 1] = C[i].p;
    }
    // for(int i = 0; i < n; i ++) cout << Now[i].p << " " << Now[i].to << endl;
    for(int i = 1; i <= n; i ++) {
        // cout << Now[i - 1].p << " " << Now[2].to << endl;
        while(Now[i - 1].p != Now[i - 1].to) {
            ans.push_back({Now[i - 1].p, Now[i - 1].to});
            int to = Now[i - 1].to;
            swap(Now[i - 1], Now[to - 1]);
            Now[i - 1].p = i, Now[to - 1].p = to;
            Now[i - 1].tag ^= 1, Now[to - 1].tag ^= 1;
        }
    }
    int pre = -1;
    for(int i = 1; i <= n; i ++) {
        if(pre > -1 && Now[i].tag) {
            if(pre == 1 && i == n) {
                ans.push_back({pre, i});
                ans.push_back({i, n - 1});
                ans.push_back({pre, n - 1});
                ans.push_back({i, n - 1});
                // printf("%d %d\n%d %d\n%d %d\n%d %d\n", , i, n - 1, pre, n - 1, i, n - 1);
            }
            else if(pre != 1) {
                ans.push_back({pre, i});
                ans.push_back({i, 1});
                ans.push_back({pre, 1});
                ans.push_back({i, 1});
                // printf("%d %d\n%d %d\n%d %d\n%d %d\n", pre, i, i, 1, pre, 1, i, 1);
            }
            else if(i != n) {
                ans.push_back({pre, i});
                ans.push_back({i, n});
                ans.push_back({pre, n});
                ans.push_back({i, n});
                // printf("%d %d\n%d %d\n%d %d\n%d %d\n", pre, i, i, n, pre, n, i, n);
            }
            pre = -1;
        }
        else if(pre == -1 && Now[i].tag) pre = i;
    }
    printf("%d\n", ans.size());
    for(auto it : ans) printf("%d %d\n", it.first, it.second);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}