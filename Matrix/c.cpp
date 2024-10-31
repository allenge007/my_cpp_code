#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;
const int maxn = 1005;
int n, q, a[maxn], box[maxn];
void solve() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        if(!num) box[++ num] = q;
        int p = 0;
        for(int j = 1; j <= num; j ++) {
            if(box[j] >= a[i] && (!p || box[j] < box[p])) p = j;
        }
        if(!p) {
            box[++ num] = q - a[i];
        } else box[p] -= a[i];
    }
    printf("%d\n", num);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}