#include <bits/stdc++.h>

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    k --;
    while(k) cnt ++, k >>= 1;
    cout << cnt << endl;
    return 0;
}