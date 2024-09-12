#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn << 1], b[maxn << 1], n;
inline int zw(int x, int y, int z) {
    int c[3] = {x, y, z};
    sort(c, c + 3);
    return c[1];
}
void spread() {
    b[1] = 0, b[2 * n - 1] = 0;
    for(int i = 2; i <= 2 * n - 2; i ++) {
        b[i] = zw(a[i - 1], a[i], a[i + 1]);
    }
    for(int i = 1; i <= 2 * n - 1; i ++)
        a[i] = b[i];
    // for(int i = 1; i <= 2 * n - 1; i ++) cout << a[i] << " ";
    // cout << endl;
}
int main() {
    freopen("53.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n - 1; i ++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= min(n - 1, 1000); i ++) {
        spread();
    }
    printf("%d", a[n]);
    return 0;
}