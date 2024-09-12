#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], n, sum;
__int128 f[maxn][2];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
    if(sum & 1) return printf("No\n"), 0;
    f[0][0] = 1;
    // cout << sum << endl;
    for(int i = 1; i <= n; i ++) {
        for(int j = sum/2; j >= a[i]; j --) {
            if(f[j - a[i]][0]) f[j][1] += f[j - a[i]][0];
            if(f[j - a[i]][1]) f[j][0] += f[j - a[i]][1];
        }
    }
    if(f[sum/2][0] >= 4) printf("Yes\n");
    else printf("No\n");
    return 0;
}