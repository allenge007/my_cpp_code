#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    cout << (n - x) * a + x * b << endl;
}
int main() {
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}