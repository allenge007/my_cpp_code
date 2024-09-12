#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1000000007;
vector<int> card[4];
int ans[maxn];
long long C, M;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    int n, k;
    scanf("%lld%lld%d%d", &C, &M, &n, &k);
    for(int i = 1; i <= n; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        card[a].push_back(b);
    }
    if(n > k) return putchar('0'), 0;
    for(int i = 1; i <= 3; i ++)
        sort(card[i].begin(), card[i].end(), cmp);
    int cnt = 0, cnt2 = 0;
    long long fac = 1ll;
    for(auto it : card[3]){
        if(it > 1) cnt ++;
    }
    for(int i = 0, len = card[3].size(); i < len; i ++) {
        fac *= card[3][i];
        if(fac > 1000) {
            cnt2 = i;
            break;
        }
    }
    for(int i = 0, len = card[1].size(); i < len; i ++)
        card[1][i] += card[1][i - 1];
    for(int i = 0, len = card[2].size(); i < len; i ++)
        card[2][i] += card[2][i - 1];
    for(int j = 0; j <= k; j ++) {
        if(j >= cnt1) 
    }
    printf("%lld", fac * nC % mod * nM % mod);
    return 0;
}