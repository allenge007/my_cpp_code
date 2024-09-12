#include <bits/stdc++.h>

using namespace std;
const int maxn = 25;
int a[maxn], b[maxn];
int main() {
    int n, las = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
        if(a[i] >= las) {
            las = a[i] + b[i];
            cout << las << " " << b[i] << " " << 0 << endl;
        }
        else {
            cout << las + b[i] << " " << las + b[i] - a[i] << " " << las - a[i] << endl;
            las += b[i];
        }
    }
    return 0;
}