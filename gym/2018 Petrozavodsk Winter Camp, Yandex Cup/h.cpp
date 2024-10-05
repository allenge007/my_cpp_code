#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 5;
int s[maxn];
vector<int> ans;
int main() {
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    if(n < k) return printf("-1\n"), 0;
    s[0] = 1;
    for(int i = 1; i <= k; i ++) {
        scanf("%d", &s[i]);
        if(s[i] == -1) s[i] = s[i - 1];
        if(s[i] < s[i - 1]) return printf("-1\n"), 0;
    }
    n -= k;
    s[k + 1] = m;
    for(int i = 1; i <= k; i ++) {
        int lft = m;
        while(n && lft > s[i]) {
            ans.push_back(lft --);
            n --;
        }
        ans.push_back(s[i]);
    }
    if(n) return printf("-1\n"), 0;
    for(auto it : ans) printf("%d ", it);
    return 0;
}