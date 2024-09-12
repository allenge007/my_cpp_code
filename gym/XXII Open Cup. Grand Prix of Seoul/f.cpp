#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 5;
char str[maxn];
int a[maxn], cho[maxn], cnt;
int main() {
    int n;
    scanf("%d%s", &n, str + 1);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 2; i <= n; i ++) {
        if(str[i] != str[i - 1]) {
            cho[++ cnt] = a[i];
        }
        else cho[cnt] = max(cho[cnt], a[i]);
    }
    cnt --;
    if(cnt <= 0) return putchar('0'), 0;
    sort(cho + 1, cho + cnt + 1, [](int x, int y) {
        return x > y;
    });
    long long ans = 0;
    // for(int i = 1; i <= cnt; i ++) cout << cho[i] << " ";
    for(int i = 1; i <= (cnt + 1)/2; i ++) ans += cho[i];
    printf("%lld\n", ans);
    return 0;
}