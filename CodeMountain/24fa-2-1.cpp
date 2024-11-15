#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 6;
int n, f[maxn], dep[maxn], num[maxn];
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    dep[1] = 1;
    int maxi = 0;
    for(int i = 2; i <= n; i ++) cin >> f[i], dep[i] = dep[f[i]] + 1, num[dep[i]] ++, maxi = max(maxi, dep[i]);
    
    return 0;
}