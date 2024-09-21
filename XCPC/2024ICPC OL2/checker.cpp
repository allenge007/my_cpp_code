#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 10;

ll a[N], b[N];
int s[N], n;

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    // srand(time(0));
    // int n = rand();

    // freopen("test.in", "w", stdout);
    
    // system("D:/OI/Contest/bin/i.exe < test.in > test.out");

    // freopen("test.out", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%lld%lld", &s[i], &a[i], &b[i]);
        ll ans = 0;
        for (int j = 1; j <= i; j++) {
            int lcp = 0;
            while (j + lcp <= i && s[1 + lcp] == s[j + lcp]) lcp++;
            for (int k = 1; k <= lcp; k++)
                ans += a[k + j - 1] * b[j];
        }
        printf("%lld\n", ans);
    }

    return 0;
}
/*
9
0 1 10
10
1 2 11
30
1 3 12
60
0 4 13
152
1 5 14
267
2 6 15
327
0 7 16
509
1 8 17
717
3 9 18
807
*/