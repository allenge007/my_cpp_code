#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int c[maxn], n;
int main() {
    long long b = 1500;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        b += x;
        if(b >= 4000) return printf("%d\n", i), 0;
    }
    printf("-1\n");
    return 0;
}