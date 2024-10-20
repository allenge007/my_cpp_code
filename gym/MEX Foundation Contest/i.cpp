#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e5 + 5;
int head[maxn], Next[maxn << 1], ver[maxn << 1], tot;
void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
int n, m, d[maxn];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &d[i]);
    }
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for(int i = 1; i <= n; i ++) {
        if(d[i] != 0) continue;
        bool flag = 1;
        for(int j = head[i]; j; j = Next[j]) {
            if(d[ver[j]] != 1) {
                flag = 0;
                break;
            }
        }
        if(flag) return printf("%d\n", i), 0;
    }
    return 0;
}