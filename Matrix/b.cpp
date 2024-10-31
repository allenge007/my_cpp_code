#include <cstdio>

using namespace std;
const int maxn = 5e5 + 5;
struct node{
    node *pre, *nxt;
    int val;
    node(node *pre = nullptr, node *nxt = nullptr, int val = 0): pre(pre), nxt(nxt), val(val) {}
}a[maxn];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    node head;
    head.val = 0;
    head.pre = nullptr, head.nxt = &a[1];
    for(int i = 1; i <= n; i ++) {
        a[i].val = i;
        if(i > 1) a[i].pre = &a[i - 1];
        if(i < n) a[i].nxt = &a[i + 1];
    }
    a[1].pre = &head;
    for(int i = 1; i <= m; i ++) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        auto Next = a[x].nxt, Pre = a[x].pre;
        if(Next != nullptr) Next -> pre = Pre;
        if(Pre != nullptr) Pre -> nxt = Next;
        if(opt == 1) {
            a[y].pre -> nxt = &a[x];
            a[x].nxt = &a[y];
            a[x].pre = a[y].pre;
            a[y].pre = &a[x];
        } else {
            if(a[y].nxt != nullptr) a[y].nxt -> pre = &a[x];
            a[x].nxt = a[y].nxt;
            a[y].nxt = &a[x];
            a[x].pre = &a[y];
        }
    }
    auto it = head.nxt;
    while(it != nullptr) {
        printf("%d ", it -> val);
        it = it -> nxt;
    }
    printf("\n");
    for(int i = 1; i <= n; i ++) a[i].pre = a[i].nxt = nullptr;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}