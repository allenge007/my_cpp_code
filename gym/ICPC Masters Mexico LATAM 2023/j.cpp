#include <bits/stdc++.h>

using namespace std;
const int maxn = 55;
int N, K, F;
long long S[maxn];
int main() {
    scanf("%d%d%d", &N, &K, &F);
    for(int i = 1; i <= F; i ++) {
        int f;
        scanf("%d", &f);
        for(int j = 1; j <= f; j ++) {
            int x;
            scanf("%d", &x);
            S[i - 1] |= (1ll << x - 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << F); i ++) {
        long long X = 0;
        int num = 0;
        for(int j = 0; j < F; j ++) {
            if((i >> j) & 1) X |= S[j], num ++;
        }
        int cnt = 0;
        while(X) X -= X & -X, cnt ++;
        if(N - cnt >= K) ans = max(ans, num);
    }
    printf("%d\n", ans);
    return 0;
}