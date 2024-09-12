#include <bits/stdc++.h>

using namespace std;
int a[4][4], b[4][4];
pair<int, int> unfold(int x) {
    return {(x - 1)/3 + 1, x % 3 == 0 ? 3 : x % 3};
}

void solve() {
    for(int i = 1; i <= 3; i ++)
        for(int j = 1; j <= 3; j ++)
            scanf("%d", &a[i][j]);
    int ans = 0;
    
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}