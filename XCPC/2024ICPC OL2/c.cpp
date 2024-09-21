#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

ll a[N], b[N], sum[N], pre[N], ans = 0;
int s[N];
int fail[N], n;

int main() { 
    // freopen("test.in", "r", stdin);
    // freopen("myans.out", "w", stdout); 
    cin >> n;
    for (int i = 1, j = 0; i <= n; i++) {
        scanf("%d%lld%lld", &s[i], &a[i], &b[i]);
        pre[i] = pre[i - 1] + b[i];
        // s[i] = (s[i] + ans % n) % n;
        ll tot = 0;
        if (i == 1) fail[i] = j = 0;
        else {
            while (j && s[j + 1] != s[i]) j = fail[j];
            if (s[i] == s[j + 1]) j++;
            fail[i] = j;
        }
        int p = fail[i];
        while(p) {
            tot += b[i - p + 1];
            p = fail[p];
        }
        for (int j = 1; j * j < i; j++)
            if ((i - 1) % j == 0) {
                sum[j] += b[i];
                if ((i - 1) / j != j) sum[(i - 1) / j] += b[i];
            }
        int k = i - fail[i], cnt = i / k;
        int pos = cnt * k + 1;
        ans += (b[1] + sum[i - fail[i]] + pre[fail[j]]) * a[i];
        // if (cnt == 2) ans += (pre[i] - pre[pos])
        printf("%lld\n", ans);
    }
    return 0;
}