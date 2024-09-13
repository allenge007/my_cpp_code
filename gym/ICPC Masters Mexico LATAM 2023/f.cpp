#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int A, B, S[maxn];
int solve(int x) {
    if(!x) return 0;
    if(S[x]) return S[x];
    int cnt = 0, y = x;
    while(y) cnt += (y % 10) * (y % 10), y /= 10;
    S[x] = min(x, cnt);
    return S[x] = min(S[x], solve(cnt));;
}
int main() {
    scanf("%d%d", &A, &B);
    long long ans = 0;
    for(int i = A; i <= B; i ++) ans += solve(i);
    printf("%lld\n", ans);
    return 0;
}