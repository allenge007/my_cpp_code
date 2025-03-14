#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int n;
long long a[maxn], sum[maxn];
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n + 1; i ++) sum[i] = 0;
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for(int i = n; i >= 1; i --) sum[i] = sum[i + 1] + a[i];
    long long maxi = a[n];
    for(int i = n - 1; i >= 1; i --) {
        if(a[i] - maxi > maxi * (n - i) - sum[i + 1]) {
            long long tmp = a[i] - maxi - maxi * (n - i) + sum[i + 1];
            maxi += tmp / (n - i + 1);
            if(tmp % (n - i + 1)) maxi ++;
        }
    }
    for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i]; 
    long long mini = a[1];
    for(int i = 2; i <= n; i ++) {
        if(mini - a[i] > sum[i - 1] - mini * (i - 1)) {
            long long tmp = mini - a[i] - sum[i - 1] + mini * (i - 1);
            mini -= tmp / i;
            if(tmp % i) mini --;
        }
    }
    printf("%lld\n", maxi - mini);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}