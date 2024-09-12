#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int M, ans;
vector<int> a[maxn], b, cmax, cmini;
signed main() {
    scanf("%lld", &M);
    for(int i = 1; i <= M; i ++) {
        int N;
        scanf("%lld", &N);
        for(int j = 0; j < N; j ++) {
            int x;
            scanf("%lld", &x);
            a[i].push_back(x);
        }
    }
    for(int i = 1; i <= M; i ++) {
        int N = a[i].size();
        if(N % 2 == 0) {
            if(N == 2) b.push_back(abs(a[i][0] - a[i][1])), ans += min(a[i][0], a[i][1]);
            else {
                int sum = a[i][N/2 - 1] + a[i][N/2] + a[i][N/2 + 1];
                int mini = min(a[i][N/2 - 1], min(a[i][N/2], a[i][N/2 + 1])), maxi = max(a[i][N/2], max(a[i][N/2 - 1], a[i][N/2 + 1]));
                int ans1 = sum - mini - maxi;
                sum = a[i][N/2 - 2] + a[i][N/2 - 1] + a[i][N/2];
                mini = min(a[i][N/2 - 1], min(a[i][N/2 - 2], a[i][N/2])), maxi = max(a[i][N/2], max(a[i][N/2 - 1], a[i][N/2 - 2]));
                int ans2 = sum - mini - maxi;
                b.push_back(abs(ans1 - ans2));
                ans += min(ans1, ans2);
            }
        }
    }
    sort(b.begin(), b.end());
    // for(auto it : b) cout << it << " ";
    // cout << endl;
    int cnt = 0;
    for(int i = b.size() - 1; i >= 0; i -= 2) {
        ans += b[i], cnt ++;
    }
    for(int i = 1; i <= M; i ++) {
        int N = a[i].size();
        if(N % 2) {
            if(N == 1) ans += a[i][0];
            else {
                int sum = a[i][N/2 - 1] + a[i][N/2] + a[i][N/2 + 1];
                int mini = min(a[i][N/2 - 1], min(a[i][N/2], a[i][N/2 + 1])), maxi = max(a[i][N/2], max(a[i][N/2 - 1], a[i][N/2 + 1]));
                if(maxi == mini) ans += mini;
                else if(maxi == a[i][N/2]) {
                    if(cnt % 2 == 0) ans += sum - maxi - mini;
                    else ans += maxi;
                }
                else if(mini == a[i][N/2]) {
                    if(cnt % 2 == 0) ans += mini;
                    else ans += ans += sum - maxi - mini;
                }
                else ans += sum - maxi - mini;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}