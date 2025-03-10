#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int w[maxn][maxn];
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++)
            cin >> w[i][j];
    }
    for(int k = 0; k < n; k ++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                w[i][j] |= w[i][k] & w[k][j];
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}