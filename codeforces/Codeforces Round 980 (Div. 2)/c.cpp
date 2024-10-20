#include <bits/stdc++.h>

using namespace std;
#define fir first
#define sec second
const int maxn = 1e5 + 5;
struct node{
    int a, b, id;
}a[maxn];
bool cmp(node x, node y) {
    return min(x.a, x.b) == min(y.a, y.b) ? max(x.a, x.b) < max(y.a, y.b) : min(x.a, x.b) < min(y.a, y.b);
}
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d", &a[i].a, &a[i].b);
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i ++) printf("%d %d ", a[i].a, a[i].b);
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}