#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], cnt[maxn], n, k, sum[maxn];
void solve() {
    scanf("%d%d", &n, &k);
    map<int, int> mp;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), mp[a[i]] ++;
    queue<int> q;
    int las = 0, sum = 0, ans = 0;
    for(auto it : mp) {
        if(!las || it.first == las + 1) {
            q.push(it.second), sum += it.second;
            while(q.size() > k) {
                sum -= q.front();
                q.pop();
            }
            ans = max(ans, sum);
            las = it.first;
        } else {
            while(!q.empty()) q.pop();
            las = it.first;
            q.push(it.second), sum = it.second;
            ans = max(ans, sum);
        }
    }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}