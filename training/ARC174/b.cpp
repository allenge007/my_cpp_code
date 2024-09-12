#include <bits/stdc++.h>

using namespace std;
long long n, A[10], point, num, p[10];
void solve() {
    point = num = 0;
    for(int i = 1; i <= 5; i ++)
        scanf("%lld", &A[i]), point += A[i] * i, num += A[i];
    for(int i = 1; i <= 5; i ++) 
        scanf("%lld", &p[i]);
    if(3ll * num - point <= 0) {
        printf("0\n");
        return ;
    }
    long long k = 3ll * num - point;
    long long ans = 0ll;
    if(p[5] <= p[4] * 2) {
        ans += k/2ll * p[5];
        k %= 2;
        if(k and p[4] <= p[5]) ans += p[4];
        else if(k) ans += p[5];
        printf("%lld\n", ans);
        return ;
    }
    ans += k * p[4];
    printf("%lld\n", ans);
    return ;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}