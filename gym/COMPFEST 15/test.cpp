#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cout << i << " ";
    cout << endl;
    for(int i = 1; i <= n; i ++) {
        cout << (i * k - 1) % n + 1 << " ";
    }
    return 0;
}